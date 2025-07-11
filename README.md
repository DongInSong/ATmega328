# ATmega328

## 개요
아두이노 기초부터 센서 및 액츄에이터 활용까지 단계적으로 학습한 프로젝트 모음  
마지막 프로젝트에서는 모든 구성 요소를 통합하여, 센서를 활용한 스마트 자동문 시스템을 구현

## 구성 요소
- LED
- 버튼
- 초음파 센서 (HC-SR04)
- 서보모터 (SG90)
- 디스플레이 (LCD)
- 배열, 조건문, 반복문, 비트 연산자 등 기초 C 언어 로직

## 파일

| 디렉토리            | 내용                      |
| --------------- | ----------------------- |
| `Final_servo`        | 컴포넌트 통합 자동문    |
| `H3_1`     | 버튼 검사       |
| `H3_2` | 비트 위치의 LED           |
| `HW4_1`      | [인터럽트] 버튼 검사              |
| `HW4-2`    | [인터럽트] 타이머 LED     |
| `array, bitwise`   | 기본 배열, 비트연산자 |


## Final Project - Servomotor & timer
![final](https://github.com/user-attachments/assets/867a5cdf-8a24-4c2d-80b2-72eef88b8586)

- 기능 요구 사항
  1. 처음 시작시, LCD에 "Initializing..." 메세지 표시
  2.  문 닫힌 상태에서, 버튼 누르면 문 열림 (180도 회전)
  3. 문 닫힌 상태에서, 초음파 센서 5 ~ 15cm 이내 물건이 감지되면 문 열림
  4. 문 열린 상태에서, LCD에 "Welcome" 메세지 표시
  5. 문 열린 상태에서, 5초 경과 후, 문 닫힘
  6. 문 열린 상태에서, 버튼 누르면 문 계속 열림
  7. 문 열린 상태에서, 버튼을 누르면 마지막 버튼을 누른 시점으로부터 5초 경과 후, 문 닫힘
  8. 문 닫힐 때, LCD에 "Welcome" 메세지 삭제

- 추가 기능
  1. 문 닫힌 상태에서, 빨간 LED 점등
  2. 문 열린 상태에서, LCD에 경과 시간 표시
  3. 문 열린 상태에서, 경과 시간에 맞추어 초록 LED 순차 점등
  4. 문 열린 상태에서, 초음파 센서 5 ~ 15cm 이내 물건이 감지되면, 감지 시점으로부터 5초 경과 후 문 닫힘

## 참고
![포트](https://github.com/user-attachments/assets/3dc5e280-0ea9-40ec-b4ca-5b491bbe36c6)
