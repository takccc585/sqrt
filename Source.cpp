#include <SFML/Graphics.hpp>
#include<ctime>


using namespace sf;
using namespace std;

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;
const string WINDOW_TITLE = "SFML Lesson 2";


int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	srand(time(nullptr));
	//������ ������
	const size_t size = 8;
	CircleShape arr_circles[size];
	/*for (int i = 0; i < size;i++) {
		float radius = 200.f - 40.f * i;
		arr_circles[i].setRadius(radius);
		arr_circles[i].setFillColor(Color{(Uint8)(rand()%256),(Uint8)(rand() % 256),(Uint8)(rand() % 256)});
		arr_circles[i].setPosition((WINDOW_WIDTH-2*radius)/2, (WINDOW_HEIGHT - 2 * radius) / 2);
	}*/
	//������ ���������
	/*RectangleShape arr_rect[size];
	srand(time(nullptr));
	const float a = 50.f;
	for (int i = 0; i < size; i++) {
		arr_rect[i].setSize(Vector2f(50.f,50.f));
		arr_rect[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
		arr_rect[i].setPosition((a + a) * i, 0);
	}
	RectangleShape arr_rect1[size];
	for (int i = 0; i < size; i++) {
		arr_rect1[i].setSize(Vector2f(50.f, 50.f));
		arr_rect1[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
		arr_rect1[i].setPosition((WINDOW_WIDTH - a) ,50.f + (a+a)*i);
	}*/
	//������ ���������� �������
	RectangleShape arr_rect[size];
	RectangleShape arr_rect1[size];
	float high = 0.f;
	float high1 = 0.f;
	for (int i = 0; i < size; i++) {
		//������ ����
		srand(time(nullptr));
		const float a = 50.f;
		high = i * 50.f;
		high1 = 50.f+(i * 50.f);
		for (int i = 0; i < size; i++) {
			arr_rect[i].setSize(Vector2f(50.f, 50.f));
			arr_rect[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
			arr_rect[i].setPosition((a + a) * i, high);
		}
		for (int i = 0; i < size; i++) {
			arr_rect1[i].setSize(Vector2f(50.f, 50.f));
			arr_rect1[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
			arr_rect1[i].setPosition(50.f+((a + a) * i), high1);
		}
	}
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ��������� ���� 
		for (int i = 0; i < size; i++) {
			for (int i = 0; i < size; i++) {
				window.draw(arr_rect[i]);
			}
			for (int i = 0; i < size; i++) {
				window.draw(arr_rect1[i]);
			}
		}
		window.display();
	}

	return 0;
}