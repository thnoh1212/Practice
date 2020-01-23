package 리듬게임;

public class Main {

	public static final int SCREEN_WIDTH = 1280;
	public static final int SCREEN_HEIGHT = 720;
	public static final int NOTE_SPEED = 3;
	public static final int SLEEP_TIME = 10;
	public static final int REACH_TIME = 2;
	
	// public static -> 모든 프로젝트 내부에서 공유 가능한 변수
	// final -> 한번 선언시 변경 불가. 즉 상수
	// 상수를 선언시에는 이름 전체를 대문자로
	public static void main(String[] args) {
		
		new DynamicBeat();
	}

}
