package �������;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;

import javazoom.jl.player.Player;


public class Music extends Thread{
	// ������� �ϳ��� ���� ���α׷��̶�� �� �� ����

	private Player player;
	private boolean isLoop;
	// ���ѹݺ����� �ƴ��� ����
	private File file;
	private FileInputStream fis;
	private BufferedInputStream bis;
	
	public Music(String name, boolean isLoop) { // ���� �ݺ���� �Լ�
		try {
			this.isLoop = isLoop;
			file = new File(Main.class.getResource("../music/" + name).toURI());
			//�������� ��ġ�� �޾ƿ�
			fis = new FileInputStream(file);
			bis = new BufferedInputStream(fis);
			player = new Player(bis);
			//������ ���ۿ� ���� �� ����
		} catch (Exception e) { // ���� �߻��� �ش� ���� ���
			System.out.println(e.getMessage());
		}
	}
	
	public int getTime() { // ���� ����ð� ǥ��
		if(player == null)
			return 0;
		return player.getPosition();
	}
	
	public void close( ) { // ����Ǵ� �� ���� �Լ�
		isLoop = false;
		player.close();
		this.interrupt();
		// interrupt -> ����Ǵ� �����带 ����
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
