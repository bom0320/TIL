import React, { useEffect } from 'react';
import { Alert } from 'react-native';
import CommonGoogleButton from '../CommonGoogleButton';
import * as AuthSession from 'expo-auth-session';
import { useNavigation } from '@react-navigation/native';

// AuthSession.makeRedirectUri: OAuth 인증 후 결과를 받기 위한 리다이렉트 URL 생성
// useProxy: Expo 개발 환경에서 리다이렉트 URL 를 Expo 의 프록시 서버를 통해 처리
// 예시 리다이렉트 URI: https://auth.expo.io/@username/your-app-slug

const REDIRECT_URI = AuthSession.makeRedirectUri({ useProxy: true }); // 리다이렉트 URI 설정
나
export default function GoogleLoginButton() {
  const navigation = useNavigation();

  // 세션 확인 함수
  // 역할 : Google 로그인 후 백엔드 서버에서 세션이 유지되고 있는지 확인인
  const checkSession = async () => {
    try {
      const response = await fetch('https://your-backend.com/auth/session', {
        // https://your-backend.com/auth/session: 세션 확인을 위한 백엔드 API URL
        // credentials: 'include' : 쿠키 같은 인증 정보(세션)를 요청에 포함

        method: 'GET',
        credentials: 'include',
      });

      if (response.ok) {
        // 성공(response.ok) → nava-navigation.replace('Main') 을 호출해 메인 화면으로 이동

        console.log('세션 유지 확인 성공');
        navigation.replace('Main'); // 메인 화면 이동
      } else {
        Alert.alert('세션 만료', '로그인이 필요합니다.');
      }
    } catch (error) {
      console.error('세션 확인 오류:', error);
      Alert.alert('오류', '세션 확인 중 문제가 발생했습니다.');
    }
  };

  // Google 로그인 함수
  const handleGoogleLogin = async () => {
    console.log('Google 로그인 시작');
    try {
      // authUrl 생성: Google OAuth 로그인 URL 생성

      const authUrl = `https://accounts.google.com/o/oauth2/v2/auth` +
        `?client_id=YOUR_GOOGLE_CLIENT_ID` + // Google API 클라이언트 ID
        `&redirect_uri=${encodeURIComponent(REDIRECT_URI)}` +
        `&response_type=token` +
        `&scope=profile%20email`;
        // redirect_uri: 인증 완료 후 되돌아올 리다이렉트 URI
        //response_type=token: 로그인 성공 시 액세스 토큰 반환.
        //scope: 요청할 정보 권한 (프로필 정보와 이메일).

      const result = await AuthSession.startAsync({ authUrl });
        // AuthSession.startAsync: 사용자를 Google 로그인 페이지로 이동시키고, 인증 결과를 반환 
        // result 객체 : 로그인 상태와 결과를 포함


      // 인증 결과 처리
      if (result.type === 'success') {
        console.log('Google 로그인 성공:', result);
        const { access_token } = result.params; // 액세스 토큰 확인
        // 애ㄱ세스 토큰을 받아 백엔드에 전송 -> 백엔드에서 세션이나 사용자 정보를 저장
        // 이후 checkSession 함수 호출 -> 세션이 유지되면 메인 화면으로 이동동
        await fetch('https://your-backend.com/auth/google', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({ token: access_token }), // 백엔드에 토큰 전달
        });
        await checkSession(); // 세션 확인
      } else if (result.type === 'cancel') {
        Alert.alert('로그인 취소', '로그인을 취소하셨습니다.');
      } else {
        Alert.alert('로그인 실패', '다시 시도해주세요.');
      }
    } catch (error) {
      console.error('Google Login Error:', error);
      Alert.alert('로그인 오류', '다시 시도해주세요.');
    }
  };

  return <CommonGoogleButton onPress={handleGoogleLogin} text="Google로 로그인" />;
  // CommonGoogleButton: 
  // onPress : 버튼을 클릭하면 handleGoogleLogin 함수 실행
  // text= "Google 로 로그인" 버튼에 표시될 텍스트

}


// 전체 흐름
// 1. 사용자가 Google 로그인 버튼을 클릭하면 Google 로그인 페이지로 이동
// 2. 로그인이 성공하면 Google 은 리다이렉트 URL 로 되돌아가며 액세스 토큰을 전달
// 3. 앱은 액세스 토큰을 서버에 전달하여 사용자 세션을 확인
// 4. 세션 확인에 성공하면 메인 화면으로 이동