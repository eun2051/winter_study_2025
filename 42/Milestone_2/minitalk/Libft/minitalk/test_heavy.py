import subprocess
import random
import time

def get_random_unicode_chunk(length=5000): # 인자 제한 안 걸릴 정도의 길이
    ranges = [(0x0020, 0x007E), (0xAC00, 0xD7A3), (0x1F600, 0x1F64F)]
    return "".join(chr(random.randint(r[0], r[1])) for _ in range(length) for r in [random.choice(ranges)])

pid = input("Server PID: ")
total_sent = 0

print("🔥 Starting Infinite Unicode Attack... Press Ctrl+C to stop.")

try:
    while True:
        payload = get_random_unicode_chunk()
        # 한 번에 안 보내고 클라이언트를 계속 실행해서 누적시킴
        subprocess.run(["./client", pid, payload], check=True)
        total_sent += len(payload.encode('utf-8'))
        print(f"🚀 Sent so far: {total_sent} bytes", end='\r')
except KeyboardInterrupt:
    print(f"\n🛑 Stopped. Total data sent: {total_sent} bytes")
