package java_project;

import javax.sound.midi.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// PianoProject 클래스
public class PianoProject extends JFrame {
	// 이 클래스는 Java 의 JFrame 을 상속받아 GUI 창을 생성한다.
	// 프로그램이 실행되면 이 클래스의 인스턴스가 생성되어 피아노 건반이 표시된다.
	

    private Synthesizer synth;
    private MidiChannel channel;
    private int[] whiteNotes = {60, 62, 64, 65, 67, 69, 71, 72};
    private int[] blackNotes = {61, 63, 66, 68, 70};
    private String[] whiteLabels = {"도", "레", "미", "파", "솔", "라", "시", "도"};

    public PianoProject() throws Exception {
    	
    // MIDI 설정
        // MIDI 설정
        synth = MidiSystem.getSynthesizer(); // MIDI 음을 생성하기 위한 신시사이저를 가져온다
        synth.open(); // 신시사이저를 초기화한다.
        channel = synth.getChannels()[0]; // 첫 번째 MIDI 채널을 가져온다. 이 채널은 음을 재생하는 데 사용된다.

        JLayeredPane layeredPane = new JLayeredPane();
        setContentPane(layeredPane);
        int whiteKeyWidth = 60;
        int blackKeyWidth = 40;
        int whiteKeyHeight = 200;
        int blackKeyHeight = 120;

     // 흰 건반과 검은 건반 버튼 생성
        
        // 흰 건반 생성
        for (int i = 0; i < whiteNotes.length; i++) {
            JButton whiteKey = createKey(whiteNotes[i], whiteLabels[i], whiteKeyWidth, whiteKeyHeight, Color.WHITE);
            whiteKey.setBounds(i * whiteKeyWidth, 0, whiteKeyWidth, whiteKeyHeight);
            layeredPane.add(whiteKey, JLayeredPane.DEFAULT_LAYER); // 흰 건반을 기본 레이어에 추가
            
            // witeNotes: MIDI 음 번호를 저장한 배열로, 흰 건반의 음을 정의한다.
            // createKey : 흰 건반을 생성하고 음표 레이블을 추가한다.
            // whiteKey.setBounds : 건반의 위치와 크기를 설정한다.
            // layeredPane.add : 흰 건반을 DEFAULT_LAYER에 추가한다.
        }

        // 검은 건반 생성
        int[] blackPositions = {0, 1, 3, 4, 5}; // 검은 건반이 있을 위치 인덱스
        for (int i = 0; i < blackNotes.length; i++) {
            JButton blackKey = createKey(blackNotes[i], "", blackKeyWidth, blackKeyHeight, Color.BLACK);
            int xOffset = blackPositions[i] * whiteKeyWidth + whiteKeyWidth - blackKeyWidth / 2;
            blackKey.setBounds(xOffset, 0, blackKeyWidth, blackKeyHeight);
            layeredPane.add(blackKey, JLayeredPane.PALETTE_LAYER); // 검은 건반을 상위 레이어에 추가
        
            // blackNotes: MIDI 음 번호 배열로, 검은 건반의 음을 정의한다.
            // blackPositions: 검은 건반이 위치할 흰 건반의 인덱스를 정의한다.
            // layeredPane.add: 검은 건반을 PALETTE_LAYER에 추가해 흰 건반 위에 표시되도록 설정한다.
        }

        setTitle("Piano Project");
        setSize(whiteNotes.length * whiteKeyWidth + 20, whiteKeyHeight + 50);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                closeSynth();
            }
        });
        setVisible(true);
    }
    
  // 건반 생성 (createKey 메서드)  
    private JButton createKey(int note, String label, int width, int height, Color color) {
        JButton key = new JButton(label);
        key.setPreferredSize(new Dimension(width, height));
        key.setBackground(color);
        key.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        key.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                key.setBackground(color.darker());
                playNoteWithTimer(note, 500);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                key.setBackground(color);
            }
        });
        return key;
        
        // 건반 버튼을 생성하고 색상, 크기, 레이블을 설정한다.
        // mousePressed: 마우스 클릭 시 음을 재생하고, 건반 색상을 어둡게 한다.
        // mouseReleaed: 마우스를 떼면 건반 색상을 원래 색상으로 복원한다.
        // playNoteWithTimer: 주어진 note 를 일정 시간 동안 재생한다.
        
    }

 // 음 재생 (`playNoteWithTimer` 메서드)
    private void playNoteWithTimer(int note, int duration) {
        channel.noteOn(note, 600);
        Timer timer = new Timer(duration, e -> channel.noteOff(note));
        timer.setRepeats(false);
        timer.start();
        
        // channel.noteOn(note, 600) : 주어진 MIDI 음(note) 을 600 세기로 재생한다.
        // Timer: 지정된 시간(duration) 이 지나면 음을 멈춘다.
        // noteOff: 음을 끈다.
    }

  
  // 창 닫을 때 신시사이저 종료
    private void closeSynth() {
        if (synth != null && synth.isOpen()) {
            synth.close();
           
            // 창 닫을 때, 신시사이저를 닫아 리소스를 해제한다.
        }
    }

    public static void main(String[] args) {
        System.out.println("Piano Project 사용 방법:");
        System.out.println("1. 프로그램이 실행되면 피아노 건반이 표시됩니다.");
        System.out.println("2. 흰 건반을 클릭하면 도, 레, 미 등 기본 음이 재생됩니다.");
        System.out.println("3. 검은 건반을 클릭하면 반음(예: 도#, 레# 등)이 재생됩니다.");
        System.out.println("4. 마우스를 누르고 있으면 음이 재생되며, 떼면 음이 멈춥니다.");
        System.out.println("즐겁게 연주해보세요!");

        SwingUtilities.invokeLater(() -> {
            try {
                new PianoProject();
            } catch (Exception e) {
                e.printStackTrace();
            }
            
         // SwingUtilities.invokeLater: GUI 를 안전하게 초기화한다.
         // new PianoProject(): 프로그램을 실행하고 피아노 건반을 표시한다.   
        });
    }
}
