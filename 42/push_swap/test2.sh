#!/bin/bash

# 색상 설정
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# 파일 및 권한 확인
if [ ! -f "./push_swap" ] || [ ! -f "./checker_Mac" ]; then
    echo -e "${RED}Error: ./push_swap 또는 ./checker_Mac가 없습니다.${NC}"
    exit 1
fi
chmod +x ./checker_Mac

# 테스트 실행 함수
check_and_print() {
    local args="$1"
    local output=$(./push_swap $args)
    local steps=$(echo "$output" | sed '/^$/d' | wc -l)
    local status=$(echo "$output" | ./checker_Mac $args)

    if [ "$status" == "OK" ]; then
        printf "[%-10s] | %-5d | ${GREEN}%-3s${NC}\n" "$args" "$steps" "$status"
    else
        printf "[%-10s] | %-5d | ${RED}%-3s${NC}\n" "$args" "$steps" "$status"
    fi
}

echo -e "  ARGS       | STEPS | RESULT"
echo -e "----------------------------"

# 1. 3개 테스트 (0, 1, 2)
echo -e "${YELLOW}>>> 3 Elements Full Test${NC}"
for a in {0..2}; do for b in {0..2}; do for c in {0..2}; do
    if [[ $a != $b && $b != $c && $a != $c ]]; then
        check_and_print "$a $b $c"
    fi
done; done; done

# 2. 4개 테스트 (0, 1, 2, 3)
echo -e "\n${YELLOW}>>> 4 Elements Full Test${NC}"
for a in {0..3}; do for b in {0..3}; do for c in {0..3}; do for d in {0..3}; do
    if [[ $a != $b && $a != $c && $a != $d && $b != $c && $b != $d && $c != $d ]]; then
        check_and_print "$a $b $c $d"
    fi
done; done; done; done

# 3. 5개 테스트 (0, 1, 2, 3, 4) - 120개 케이스
echo -e "\n${YELLOW}>>> 5 Elements Full Test${NC}"
for a in {0..4}; do for b in {0..4}; do for c in {0..4}; do for d in {0..4}; do for e in {0..4}; do
    if [[ $a != $b && $a != $c && $a != $d && $a != $e && $b != $c && $b != $d && $b != $e && $c != $d && $c != $e && $d != $e ]]; then
        check_and_print "$a $b $c $d $e"
    fi
done; done; done; done; done