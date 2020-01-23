package dynamic_beat_16;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.RenderingHints;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

// JFrame�� java���� GUI����� ���α׷��� �����ϱ� ���� �⺻������ ��ӹ޾ƾ� �ϴ� Ŭ����
public class DynamicBeat extends JFrame {

	// �ڹٿ��� �����ϴ�, �ܼ��� �̹����� ȭ�鿡 ���� ����� ����ϸ�
	// ���۸��� ������ ���ϰ� �߻���. �̸� �����ϱ� ���Ͽ�
	// ������۸��̶�� ���α׷��� ����� Ȱ���� �ʿ䰡 ����.
	// ������۸��̶� ����ȭ���� ũ�⿡ �´� �̹����� �� ���� �����Ͽ�
	// �ʿ��� ������Ʈ�� ȭ�鿡 ����ϴ� ���
	// ���ۿ� �̹����� ��� �� ���� �̹����� �����ϹǷ� �̷��� ���ӿ�����
	// �ݵ�� �ʿ��� ���
	private Image screenImage;
	private Graphics screenGraphic;

	private Image background = new ImageIcon(Main.class.getResource("../images/introbackground.jpg")).getImage();
	// ������ �غ��� �� �̹��� �ҷ����� �۾�
	private JLabel menuBar = new JLabel(new ImageIcon(Main.class.getResource("../images/menuBar.png")));
	// �޴� �� �̹��� �ҷ�����

	private ImageIcon exitButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/exitButtonEntered.png"));
	private ImageIcon exitButtonBasicImage = new ImageIcon(Main.class.getResource("../images/exitButtonBasic.png"));
	private ImageIcon startButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/startButtonEntered.png"));
	private ImageIcon startButtonBasicImage = new ImageIcon(Main.class.getResource("../images/startButtonBasic.png"));
	private ImageIcon quitButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/quitButtonEntered.png"));
	private ImageIcon quitButtonBasicImage = new ImageIcon(Main.class.getResource("../images/quitButtonBasic.png"));
	// exit, start, quit ��ư �̹��� ������ �߰�
	
	private ImageIcon leftButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/leftButtonEntered.png"));
	private ImageIcon leftButtonBasicImage = new ImageIcon(Main.class.getResource("../images/leftButtonBasic.png"));
	private ImageIcon rightButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/rightButtonEntered.png"));
	private ImageIcon rightButtonBasicImage = new ImageIcon(Main.class.getResource("../images/rightButtonBasic.png"));
	// left, right ȭ��ǥ ��ư �߰�
	
	private ImageIcon easyButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/easyButtonEntered.png"));
	private ImageIcon easyButtonBasicImage = new ImageIcon(Main.class.getResource("../images/easyButtonBasic.png"));
	private ImageIcon hardButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/hardButtonEntered.png"));
	private ImageIcon hardButtonBasicImage = new ImageIcon(Main.class.getResource("../images/hardButtonBasic.png"));
	// ���̵� ���� ��ư �߰�
	
	private ImageIcon backButtonEnteredImage = new ImageIcon(Main.class.getResource("../images/backButtonEntered.png"));
	private ImageIcon backButtonBasicImage = new ImageIcon(Main.class.getResource("../images/backButtonBasic.png"));
	// �ڷΰ��� ��ư
	
	
	private JButton exitButton = new JButton(exitButtonBasicImage);
	private JButton startButton = new JButton(startButtonBasicImage);
	private JButton quitButton = new JButton(quitButtonBasicImage);
	private JButton leftButton = new JButton(leftButtonBasicImage);
	private JButton rightButton = new JButton(rightButtonBasicImage);
	private JButton easyButton = new JButton(easyButtonBasicImage);
	private JButton hardButton = new JButton(hardButtonBasicImage);
	private JButton backButton = new JButton(backButtonBasicImage);
	 
	private int mouseX, mouseY;
	//���콺 Ŀ���� X, Y��ǥ
	private boolean isMainScreen = false;
	// ����ȭ������ üũ
	private boolean isGameScreen = false;
	
	public static Game game;
	// �ϳ��� ���ӿ��� �������� �뷡�� ���ÿ� �÷��� �� �� ����
	// �̸� ���� public static �����Ͽ� ������Ʈ �� ���Ϻ������� ����
	
	ArrayList<Track> trackList = new ArrayList<Track>();

	private Image titleImage;
	// �뷡 Ÿ��Ʋ �̹���
	private Image selectedImage;
	// �� �̹��� ����
	Music introMusic = new Music("introMusic.mp3", true);
	private Music selectedMusic;
	// ���õ� �뷡
	private int nowSelected = 0; 
	
	public DynamicBeat() {

		trackList.add(new Track("Mighty Love Title Image.png", "Mighty Love Start Image.png",
				"Mighty Love Game Image.jpg", "Mighty Love Selected.mp3", "Joakim Karud-Mighty Love.mp3", "Joakim Karud-Mighty Love"));
		trackList.add(new Track("Wild Flower Title Image.png", "Wild Flower Start Image.png",
				"Wild Flower Game Image.jpg", "Wild Flower Selected.mp3", "Joakim Karud-Wild Flower.mp3", "Joakim Karud-Wild Flower"));
		trackList.add(new Track("Energy Title Image.png", "Energy Start Image.png",
				"Energy Game Image.png", "Energy Selected.mp3", "Bensound-energy.mp3", "Bensound-energy"));
		
		setUndecorated(true);
		// ���۽ÿ��� �߰���� ǥ�� X
		setTitle("Dynamic Beat");
		// ���� ����
		setSize(Main.SCREEN_WIDTH, Main.SCREEN_HEIGHT);
		// ��ü���� ����â�� ũ�� ����
		setResizable(false);
		// ���� ���� â�� ����� ���Ƿ� ���� �Ұ�
		setLocationRelativeTo(null);
		// ���� â�� ȭ�� �� ����� ��ġ
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// ����â�� ����� ������ ����ǰ� ����. (�ݵ�� ���� �ʿ�)
		setVisible(true);
		// ȭ�鿡 ���� â�� ���̰� ����.
		setBackground(new Color(0, 0, 0, 0));
		setLayout(null);

		addKeyListener(new KeyListener());
		
		introMusic.start();
		

		
		// ���� �߿�. �޴��ٰ� ���� �߰����� ��� �޴��ٰ� ��ư�� ��������� ������ ��ư�� ���� �߰��� �� �޴��� �߰�
		exitButton.setBounds(1245, 0, 30, 30);
		exitButton.setBorderPainted(false);
		exitButton.setContentAreaFilled(false);
		exitButton.setFocusPainted(false);
		// �⺻ �����Ǵ� ���ø� ����
		exitButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				exitButton.setIcon(exitButtonEnteredImage);
				exitButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				exitButton.setIcon(exitButtonBasicImage);
				exitButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				try {
					Thread.sleep(1000);
				} catch(InterruptedException ex) {
					ex.printStackTrace();
				}
				System.exit(0);
			}
		});
		add(exitButton);
		
		startButton.setBounds(40, 200, 400, 100);
		startButton.setBorderPainted(false);
		startButton.setContentAreaFilled(false);
		startButton.setFocusPainted(false);
		startButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				startButton.setIcon(startButtonEnteredImage);
				startButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				startButton.setIcon(startButtonBasicImage);
				startButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				enterMain();
			}
		});
		add(startButton);
		
		quitButton.setBounds(40, 330, 400, 100);
		quitButton.setBorderPainted(false);
		quitButton.setContentAreaFilled(false);
		quitButton.setFocusPainted(false);
		quitButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				quitButton.setIcon(quitButtonEnteredImage);
				quitButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				quitButton.setIcon(quitButtonBasicImage);
				quitButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				try {
					Thread.sleep(1000);
				} catch(InterruptedException ex) {
					ex.printStackTrace();
				}
				System.exit(0);
			}
		});
		add(quitButton);

		leftButton.setVisible(false);
		leftButton.setBounds(140, 310, 60, 60);
		leftButton.setBorderPainted(false);
		leftButton.setContentAreaFilled(false);
		leftButton.setFocusPainted(false);
		leftButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				leftButton.setIcon(leftButtonEnteredImage);
				leftButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				leftButton.setIcon(leftButtonBasicImage);
				leftButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				// ���� �̵� �߰�
				selectLeft();
			}
		});
		add(leftButton);
		
		rightButton.setVisible(false);
		rightButton.setBounds(1080, 310, 60, 60);
		rightButton.setBorderPainted(false);
		rightButton.setContentAreaFilled(false);
		rightButton.setFocusPainted(false);
		// �⺻ �����Ǵ� ���ø� ����
		rightButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				rightButton.setIcon(rightButtonEnteredImage);
				rightButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				rightButton.setIcon(rightButtonBasicImage);
				rightButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				selectRight();
				// ������ �̵� �߰�
			}
		});
		add(rightButton);
		
		
		easyButton.setVisible(false);
		easyButton.setBounds(375, 580, 250, 67);
		easyButton.setBorderPainted(false);
		easyButton.setContentAreaFilled(false);
		easyButton.setFocusPainted(false);
		// �⺻ �����Ǵ� ���ø� ����
		easyButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				easyButton.setIcon(easyButtonEnteredImage);
				easyButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				easyButton.setIcon(easyButtonBasicImage);
				easyButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				gameStart(nowSelected, "Easy");
			}
		});
		add(easyButton);
		
		hardButton.setVisible(false);
		hardButton.setBounds(655, 580, 250, 67);
		hardButton.setBorderPainted(false);
		hardButton.setContentAreaFilled(false);
		hardButton.setFocusPainted(false);
		// �⺻ �����Ǵ� ���ø� ����
		hardButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				hardButton.setIcon(hardButtonEnteredImage);
				hardButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				hardButton.setIcon(hardButtonBasicImage);
				hardButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				gameStart(nowSelected, "Hard");
			}
		});
		add(hardButton);
		
		
		backButton.setVisible(false);
		backButton.setBounds(20, 50, 60, 60);
		backButton.setBorderPainted(false);
		backButton.setContentAreaFilled(false);
		backButton.setFocusPainted(false);
		// �⺻ �����Ǵ� ���ø� ����
		backButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				backButton.setIcon(backButtonEnteredImage);
				backButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
				Music buttonEnteredMusic = new Music("buttonEnteredMusic.mp3", false);
				buttonEnteredMusic.start();
			}
			@Override
			public void mouseExited(MouseEvent e) {
				backButton.setIcon(backButtonBasicImage);
				backButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
			@Override
			public void mousePressed(MouseEvent e) {
				Music buttonEnteredMusic = new Music("buttonPressedMusic.mp3", false);
				buttonEnteredMusic.start();
				backMain();
			}
		});
		add(backButton);
		
		menuBar.setBounds(0, 0, 1280, 30);
		// �Ŵ��� ��ġ �� ũ��
		menuBar.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) { // ���콺 ��ġ �޾ƿ���
				mouseX = e.getX();
				mouseY = e.getY();
			} 
		});
		menuBar.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) { // �޴��ٸ� ���� ���·� ���� â �����̱� �߰�.
				int x = e.getXOnScreen();
				int y = e.getYOnScreen();
				setLocation(x - mouseX, y - mouseY);
			}
		});
		
		add(menuBar);
		// JFrame ���ο� ��� �߰�
	}

	public void paint(Graphics g) { // ���α׷� ȭ�� ũ�⸸ŭ �̹��� �����Ͽ� ���ϴ� �׸� �׸���

		screenImage = createImage(Main.SCREEN_WIDTH, Main.SCREEN_HEIGHT);
		// ���ϴ� �������� �̹����� �����Ͽ� �ش� ������ ����
		screenGraphic = screenImage.getGraphics();
		// ������ ������ ��ũ�� �̹����� �̿��Ͽ� �׷��� ��ü ����
		screenDraw((Graphics2D)screenGraphic);
		// ����� ���� �Լ��� ����Ͽ� �׷��� ��ü �׸���
		g.drawImage(screenImage, 0, 0, null);
		// ��ũ�� �̹����� 0,0�� ��ġ�� ����
	}

	public void screenDraw(Graphics2D g) {
		g.drawImage(background, 0, 0, null);
		// 0, 0 ��ġ�� background �׸���
		if(isMainScreen) {
			g.drawImage(selectedImage, 340, 100, null);
			//�������� ���Ե� �̹����� ���� drawimage�� ǥ��
			g.drawImage(titleImage, 340, 70, null);
		}
		if(isGameScreen) {
			game.screenDraw(g);
		}
		paintComponents(g);
		// �׷��� background ���ο� ��� �߰�. �� add�� �߰��� ��ư�� �߰�
		try {
			Thread.sleep(5);
		}catch(Exception e) {
			e.printStackTrace();
		}
		this.repaint();
		// �� �Լ��� ����Ͽ� �� ���� �̹����� �ٽ� �׸�
	}
	
	public void selectedTrack(int nowSelected) {
		if(selectedMusic != null)
			selectedMusic.close();
		titleImage = new ImageIcon(Main.class.getResource("../images/" + trackList.get(nowSelected).getTitleImage())).getImage();
		selectedImage = new ImageIcon(Main.class.getResource("../images/" + trackList.get(nowSelected).getStartImage())).getImage();
		selectedMusic = new Music(trackList.get(nowSelected).getStartMusic(), true);
		selectedMusic.start();
	}

	public void selectLeft() {
		if(nowSelected == 0)
			nowSelected = trackList.size() - 1;
		else
			nowSelected -= 1;
		selectedTrack(nowSelected);
	}
	
	public void selectRight() {
		if(nowSelected == trackList.size() - 1)
			nowSelected = 0;
		else
			nowSelected += 1;
		selectedTrack(nowSelected);
	}
	
	public void gameStart(int nowSelected, String difficulty) {
		if(selectedMusic != null)
			selectedMusic.close();
		isMainScreen = false;
		leftButton.setVisible(false);
		rightButton.setVisible(false);
		easyButton.setVisible(false);
		hardButton.setVisible(false);
		backButton.setVisible(true);
		background = new ImageIcon(Main.class.getResource("../images/" + trackList.get(nowSelected).getGameImage())).getImage();
		isGameScreen = true;
		game = new Game(trackList.get(nowSelected).getTitleName(), difficulty, trackList.get(nowSelected).getGameMusic());
		// Ű���� ��Ŀ���� ���ο� ����
		game.start();
		setFocusable(true);
	}
	
	public void backMain() {
		isMainScreen = true;
		leftButton.setVisible(true);
		rightButton.setVisible(true);
		easyButton.setVisible(true);
		hardButton.setVisible(true);
		backButton.setVisible(false);
		background = new ImageIcon(Main.class.getResource("../images/mainBackground.jpg")).getImage();	
		selectedTrack(nowSelected);
		isGameScreen = false;
		game.close();
	}
	
	public void enterMain() {
		
		startButton.setVisible(false);
		quitButton.setVisible(false);
		background = new ImageIcon(Main.class.getResource("../images/mainBackground.jpg")).getImage();
		// ȭ�� ���� (intro -> main)
		isMainScreen = true;
		leftButton.setVisible(true);
		rightButton.setVisible(true);
		easyButton.setVisible(true);
		hardButton.setVisible(true);
		// start �� quit ��ư ��Ȱ��ȭ �� �߰� ��ư Ȱ��ȭ
		introMusic.close();
		selectedTrack(0);
	}
	
}
