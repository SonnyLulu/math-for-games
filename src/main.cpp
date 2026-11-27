#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

int main()
{
	InitWindow(768, 768, "Math");

	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircleV(GetMousePosition(), 20.0f, RED);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
