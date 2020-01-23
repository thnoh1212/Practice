package 리듬게임;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;

import javazoom.jl.player.Player;


public class Music extends Thread{
	// 쓰레드는 하나의 착은 프로그램이라고도 할 수 있음

	private Player player;
	private boolean isLoop;
	// 무한반복할지 아닐지 선택
	private File file;
	private FileInputStream fis;
	private BufferedInputStream bis;
	
	public Music(String name, boolean isLoop) { // 음악 반복재생 함수
		try {
			this.isLoop = isLoop;
			file = new File(Main.class.getResource("../music/" + name).toURI());
			//음악파일 위치를 받아옴
			fis = new FileInputStream(file);
			bis = new BufferedInputStream(fis);
			player = new Player(bis);
			//파일을 버퍼에 담은 후 실행
		} catch (Exception e) { // 오류 발생시 해당 문구 출력
			System.out.println(e.getMessage());
		}
	}
	
	public int getTime() { // 음악 재생시간 표시
		if(player == null)
			return 0;
		return player.getPosition();
	}
	
	public void close( ) { // 재생되는 곡 종료 함수
		isLoop = false;
		player.close();
		this.interrupt();
		// interrupt -> 실행되던 쓰레드를 중지
	}
	
	@Override
	public void run() {
		try {
			do {
				player.play();
				fis = new FileInputStream(file);
				bis = new BufferedInputStream(fis);
				player = new Player(bis);
			} while(isLoop);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
	
	
}
