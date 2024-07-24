DATA
===
1. 1. 이론을 세우는 데 기초가 되는 사실·자료.
    
    "수출 실적에 관한 ∼"
    
2. 2. **컴퓨터**
    
    프로그램을 운용할 수 있는 형태로 기호화·숫자화한 자료. 순화어는 `자료'.
    
    **데이터는 형태에 따라 정형 데이터, 반정형 데이터, 그리고 비정형 데이터로 분류된다.** 
    

# 정형 데이터(Structed Data)

- 정형 데이터는 미리 정해 놓은 형식과 구조에 따라 저장되도록 구성하여 고정된 필드에 저장된 데이터이다.

![](https://postfiles.pstatic.net/MjAyMDExMThfMjUy/MDAxNjA1Njg1NzI4OTk5.UBEwhBg_EzxFb41CeBXDk7q9D3P3WE8W2cCAgUEXGkQg.lsv959tkZuNEmyiAYaFsuoWb_LiOr4fvaKgfw7hi8q4g.PNG.zalesia2020/database-schema-1895779_1280.png?type=w966)

- 지정된 행과 열에 데이터가 구별되어 입력되어 있으며 관계형 데이터 베이스(RDMS)의 테이블 형태로 지정된다.
- 정해진 형식과 저장 구조를 바탕으로 **손쉽게 데이터에 대한 부분 검색 및 선택, 갱신, 삭제 등의 연산을 수행할 수 있어 주로 정형화된 업무 또는 서비스에 사용**한다.

## 정형 데이터의 유형

- 정형 데이터를 숫자와 값으로 생각→ 이는 정량적인 데이터이며 Excel 파일, 웹 양식 결과 예약 시스템 및 SQL 데이터베이스의 형태로 존재
- 정형 데이터의 추가적인 유형에는 POS(Point-of-Sale) 데이터, 제품 디렉토리 및 금융 트랜잭션이 포함됨
    
    정형데이터는 다음과 같은 여러 상황과 산업에서 사용될 수 있다.
    
- **금융 서비스:** [**정형 데이터는 은행**](https://www.elastic.co/kr/customers/pscu), 회계사 및 금융 기관에서 거래, 계좌 번호 및 계좌 소유자의 이름과 같은 재무 데이터를 기록, 처리, 관리 및 분석하는 데 사용
- **여행 산업:** [**예약 사이트**](https://www.elastic.co/kr/videos/how-booking-com-is-tackling-unparalleled-growth-complexity-and-scale-with-elastic), 호텔, 항공사 및 기타 운송 회사는 고객 및 승객 데이터, 호텔 또는 항공편 가격, 버스, 기차 또는 항공편 여행 일정 및 트랜잭션을 포함하는 정형 데이터를 사용
- **의료 서비스:** [**의료 서비스**](https://www.elastic.co/kr/customers/influence-health) 산업은 환자 기록, 보험 기록 및 의료 장비 인벤토리에 정형 데이터를 사용
- **소매 및 전자 상거래:** 정형 데이터는 [**소매 및 전자 상거래**](https://www.elastic.co/kr/customers/dutch-variety-retailer)에서 제품 재고, 가격, 거래 및 사용자 계정 정보를 기록하고 저장하는 데 사용
- **공공 부문:** [**정부**](https://www.elastic.co/kr/elasticon/archive/2021/public-sector/state-local-government-education/using-a-risk-based-approach-to-provide-cost-effective-security)는 정형 데이터를 다양한 방식으로 사용.  한 가지 방법은 인구조사 데이터를 통해 특정 시간에 인구에 대한 정보를 수집하는 것 → 이 정형 데이터는 지리적 위치, 성별, 인종 및 가구원 수와 같은 것들로 구성된다.

# 비정형 데이터(Unsturctured Data)

- 비정형 데이터는 정의된 구조가 없는 동영산 파일, 오디오 파일, 사진, 보고서, 메일 본문 등과 같이 정형화되지 않은 데이터이다.
    
   ![](https://postfiles.pstatic.net/MjAyMDExMThfMjk5/MDAxNjA1Njg1NDk4NDA3.J9lz0YJ3RUxG3sYp1FU2fcTO_9PUsaUiyRIQObqJQpgg.06-uVKC0xPs6F5sCkXMDSRjlq76O9vmsKrs_2ZBSJkMg.JPEG.zalesia2020/media-998990_1920.jpg?type=w966)
    
- 정형 데이터와 반대로  형태가 없고 연산할 수 없는 데이터이다.
    
    예) 
    
    - 오디오 또는 비디오 데이터, 보안 감시 데이터, 지리 공간 데이터, 이미지 및 날씨 데이터와 같은 **리치 미디어**.
    - 장치의 티커 또는 센서 데이터와 같은 **사물 인터넷(IoT) 데이터**.
    - 이메일, 문자 메시지, 인보이스, 레코드 및 생산성 애플리케이션 통신 데이터와 같은 **텍스트 데이터**.
    - 기계가 생성한 우주 탐사 또는 지진 보고서와 같은 **과학적 데이터**.
    - MRI, X선 및 CT 스캔과 같은 의료 데이터와 영상, 의사의 노트 및 처방전과 같은 **의료 데이터 및 이미징**.
- 비정형 데이터는 데이터 구조가 없어 내용에 대한 질의 처리를 할 수 없으므로 데이터 특징을 추출하여 반정형, 또는 정형 데이터로 변환하는 전처리  과정이 필요하다.
- **페이스북, 트위터 등 웹에서 폭발적으로 생성되고 있는 비정형 데이터는 그 내용을 통해 비즈니스 미래를 예츨할 수 있다는 점에서 빅 데이터 시대의 주목**을 받고 있다.

## 비정형 데이터의 적용 분야

- 분석 시 비정형 데이터는 기업에 다양한 기회를 제공한다
- 비정형 데이터는 질적 데이터로서 기업이 고객, 고객의도 및 시장 변화를 더 잘 이해하는 데 도움이 될 수 있다 → 이를 통해 기업은 보다 우수하고 안전하며 복원력이 뛰어난 고객 환경 제공 가능
    
    비정형 데이터의 일부 적용 분야는 다음과 같다. 
    
    • **고객 경험 개선**: 고객 지원 채팅, 이메일 및 통화 내용을 분석하면 일반적인 고객 문제를 식별하고, 지원 프로토콜을 개선하며, 고객 검색 경험을 개인화하고, 고객 서비스 담당자를 보다 효과적으로 교육할 수 있다.
    
    ![](https://images.contentstack.io/v3/assets/bltefdd0b53724fa2ce/bltc46573742ba5e76e/63fe493d325d3c10b59d1e8e/blog-elastic-zero-trust-framework-diagram.png)
    
- **환자 의료 결과 예측**: 환자 의료 기록에는 종종 의사의 메모와 같은 비정형 데이터가 포함되어 있으며, 분석을 통해 패턴을 식별하고 환자 결과를 예측하거나 치료 계획을 알 수 있다.
- **부정 행위 탐지**: 금융 서비스에서는 비정형 데이터를 사용하여 부정 행위를 탐지할 수 있다.
    
    예) 이메일 통신을 분석하면 부정 행위를 나타내는 의심스러운 패턴이 나타낼 수 있음
    
- **추천 제공**: 전자상거래 플랫폼 및 스트리밍 서비스는 제품 설명 또는 동영상 스크립트와 같은 비정형 데이터를 분석하여 추천 알고리즘을 개선할 수 있다.

# 반정형 데이터(Semi-Structured Data)

- 반정형 데이터는 데이터의 구조 정보를 데이터와 함께 제공하는 파일 형식의 데이터로, 데이터 형식과 구조가 변경될 수 있는 데이터 이다.

![](https://postfiles.pstatic.net/MjAyMDExMThfMTEy/MDAxNjA1Njg1OTY5ODk5.Q6iCRpMOH9QAHAsDQoPY2k73F2fmPhK_fALQBdtd4S4g.dTF0hWjE-eMBVa9dPQgoj7-SmK4saJYC7xMgu0Vh7T4g.PNG.zalesia2020/code-3600810_1280.png?type=w966)

- 정형 데이터와 같이 테이블의 행과 열로 구조화되어 있지는 않으나 **스키마 및 메타데이터 특성을 가지고 있으며, 주로 XML, HTML, JSON 등의 파일 형태로 지정**된다.
- 반정형 데이터의 장점은 정형 데이터에 비해 확장이 더 유연하고 간단하다는 것