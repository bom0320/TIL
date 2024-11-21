package java_project;

import javax.sound.midi.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PianoProject extends JFrame {

    private Synthesizer synth;
    private MidiChannel channel;
    private int[] whiteNotes = {60, 62, 64, 65, 67, 69, 71, 72};
    private int[] blackNotes = {61, 63, 66, 68, 70};
    private String[] whiteLabels = {"도", "레", "미", "파", "솔", "라", "시", "도"};

    public PianoProject() throws Exception {
        // MIDI 설정
        synth = MidiSystem.getSynthesizer();
        synth.open();
        channel = synth.getChannels()[0];

        JLayeredPane layeredPane = new JLayeredPane();
        setContentPane(layeredPane);
        int whiteKeyWidth = 60;
        int blackKeyWidth = 40;
        int whiteKeyHeight = 200;
        int blackKeyHeight = 120;

        // 흰 건반 버튼 생성
        for (int i = 0; i < whiteNotes.length; i++) {
            JButton whiteKey = createKey(whiteNotes[i], whiteLabels[i], whiteKeyWidth, whiteKeyHeight, Color.WHITE);
            whiteKey.setBounds(i * whiteKeyWidth, 0, whiteKeyWidth, whiteKeyHeight);
            layeredPane.add(whiteKey, JLayeredPane.DEFAULT_LAYER); // 흰 건반을 기본 레이어에 추가
        }

        // 검은 건반 버튼 생성
        int[] blackPositions = {0, 1, 3, 4, 5}; // 검은 건반이 있을 위치 인덱스
        for (int i = 0; i < blackNotes.length; i++) {
            JButton blackKey = createKey(blackNotes[i], "", blackKeyWidth, blackKeyHeight, Color.BLACK);
            int xOffset = blackPositions[i] * whiteKeyWidth + whiteKeyWidth - blackKeyWidth / 2;
            blackKey.setBounds(xOffset, 0, blackKeyWidth, blackKeyHeight);
            layeredPane.add(blackKey, JLayeredPane.PALETTE_LAYER); // 검은 건반을 상위 레이어에 추가
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
    }

    private void playNoteWithTimer(int note, int duration) {
        channel.noteOn(note, 600);
        Timer timer = new Timer(duration, e -> channel.noteOff(note));
        timer.setRepeats(false);
        timer.start();
    }

    private void closeSynth() {
        if (synth != null && synth.isOpen()) {
            synth.close();
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
        });
    }
}
