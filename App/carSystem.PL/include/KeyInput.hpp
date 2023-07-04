#pragma once
#include "precompile.hpp"

class InputField
{
private:

    // Variables
    Color textColor; // Color of the text
    RectangleShape field; // Position of the input field
    
    string type; // Type of the input (text, email, password, numbers)
    string result = ""; // Result from the fields
    string input = ""; // The text from the field
    
    int maxChars; // Maximum characters in the field
    int charCount = 0; // Counts the inputed symbols
    float fontSize; // Size of the text
    
    unsigned int animationCounter; // counts frames for the animation
    
    bool isSelected = false;

    // Fonts
    Font font; // Font to use/display when typing

    

public:
    InputField(RectangleShape _mfield, Vector2f _mposition, Vector2f _msize, string type, float fontSize, Color textColor, bool haveOutline = true);
    ~InputField() = default;

    //
    //
    // Public Methods
    //
    //

	// Updates the field
    void updateField(Vector2f mousePos, RenderWindow& window, Event& event);

	// Resets the input when you exit the scene
    void resetField();

	// Changes the field position
    void changePos(float x, float y);

    // Displays the text from input
    void printInput(RenderWindow& window);

    // checks if the field is selected
    void selectField(Vector2f mousePos);


    // Handles special symbols and other input
    void handleInput(RenderWindow& window, Event& event);

	// Returns the input from the field
    string getInput();
};