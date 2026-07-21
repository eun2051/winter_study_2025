#!/bin/bash

# 사용법: ./stress_test.sh [SERVER_PID]
SERVER_PID=$1

if [ -z "$SERVER_PID" ]; then
    echo "Usage: ./stress_test.sh [SERVER_PID]"
    exit 1
fi

# 1. 무작위 유니코드 및 이모지 데이터 생성 (약 10,000자 이상)
# 한글, 일어, 아랍어, 이모지 등을 조합합니다.
DATA=$(python3 -c "print('🔥' * 1000 + '한글테스트' * 500 + '안녕하세요' * 500 + '𝔄𝔯𝔬𝔤𝔯𝔞𝔪𝔪𝔦𝔫𝔤' * 500 + '🚀' * 1000)")

echo "🚀 [INFO] Sending $(echo -n "$DATA" | wc -c) bytes of Unicode data to Server ($SERVER_PID)..."

# 2. 클라이언트 실행 (Valgrind를 씌워서 실행하면 더 빡셉니다)
valgrind --leak-check=full --show-leak-kinds=all ./client "$SERVER_PID" "$DATA"

echo -e "\n✅ [DONE] 전송 완료. 서버의 출력과 원본 데이터가 일치하는지 확인하세요."
