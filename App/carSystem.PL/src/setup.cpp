#include "../include/Setup.hpp"

bool isClicked(const Event& event) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            return true;
        }
    }
    return false;
}

void setup() {
    RenderWindow window(sf::VideoMode(1280, 720), "Rentify");
    LoginRegister logReg;
    APIHandler handler;

    window.setVerticalSyncEnabled(true);

    Image icon;
    if (!icon.loadFromFile("./assets/Icon.png")) {
        cout << "Icon not loading";
    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    string email;
    shared_ptr<Scene> sc = make_shared<Register>("reg");

    SceneManager sceneManager;
    sceneManager.switchToScene(sc);

    vector<int> vehicleIndexes;

    vehicles dataV;
    handler.passData(dataV);

    bool addCarDraw = false;

    Text rentOneText, rentTwoText, rentThreeText;

    Font font;


    if (!font.loadFromFile("./assets/fonts/SF-Pro-Text-Thin.otf"))
    {
        cout << "Font not loading";
    }

    rentOneText.setFont(font);
    rentTwoText.setFont(font);
    rentThreeText.setFont(font);

    rentOneText.setCharacterSize(24);
    rentTwoText.setCharacterSize(24);
    rentThreeText.setCharacterSize(24);

    rentOneText.setFillColor(Color::Black);
    rentTwoText.setFillColor(Color::Black);
    rentThreeText.setFillColor(Color::Black);

    rentOneText.setStyle(Text::Bold);
    rentTwoText.setStyle(Text::Bold);
    rentThreeText.setStyle(Text::Bold);

    rentOneText.setString(dataV.names.at(0));
    rentTwoText.setString(dataV.names.at(1));
    rentThreeText.setString(dataV.names.at(2));

    rentOneText.setPosition(80, 290);
    rentTwoText.setPosition(490, 290);
    rentThreeText.setPosition(900, 290);

    Text vehicleTypeText, manufacturerText, modelText, nameText;

    vehicleTypeText.setFont(font);
    manufacturerText.setFont(font);
    modelText.setFont(font);
    nameText.setFont(font);

    vehicleTypeText.setCharacterSize(30);
    manufacturerText.setCharacterSize(30);
    modelText.setCharacterSize(30);
    nameText.setCharacterSize(30);

    vehicleTypeText.setFillColor(Color::Black);
    manufacturerText.setFillColor(Color::Black);
    modelText.setFillColor(Color::Black);
    nameText.setFillColor(Color::Black);

    vehicleTypeText.setStyle(Text::Bold);
    manufacturerText.setStyle(Text::Bold);
    modelText.setStyle(Text::Bold);
    nameText.setStyle(Text::Bold);

    vehicleTypeText.setPosition(900, 85);
    manufacturerText.setPosition(1015, 230);
    modelText.setPosition(1030, 430);
    nameText.setPosition(945, 585);

    //type exactly the type in the loop to find 
    //carType choice allTypes, Car, Van, Motorcycle, Truck, SUV;
    string vehicleType = "allTypes";
    int budgetChoice = 1;

    Texture checkMarkTexture;
    checkMarkTexture.loadFromFile("./assets/credentials/tickMark.png");
    Sprite checkMark;
    checkMark.setTexture(checkMarkTexture);
    checkMark.setPosition(Vector2f(40, 505));
    checkMark.setScale(0.15f, 0.15f);
    string selectRole;

    int counter = 1;
    int counterModeRegister = 0, counterModeLogin = 0;
    sf::Clock clock;

    //vehicle hover
    Texture textureCar, textureMotorcycle, textureSuv, textureVan, textureTruck;
    textureCar.loadFromFile("./assets/credentials/hoverRentVehicle/car.png");
    textureMotorcycle.loadFromFile("./assets/credentials/hoverRentVehicle/motor.png");
    textureSuv.loadFromFile("./assets/credentials/hoverRentVehicle/suv.png");
    textureVan.loadFromFile("./assets/credentials/hoverRentVehicle/van.png");
    textureTruck.loadFromFile("./assets/credentials/hoverRentVehicle/truck.png");

    Sprite spriteCar, spriteMotorcycle, spriteSuv, spriteVan, spriteTruck;
    spriteCar.setTexture(textureCar);
    spriteCar.setPosition(55, 134);

    spriteMotorcycle.setTexture(textureMotorcycle);
    spriteMotorcycle.setPosition(170, 134);

    spriteSuv.setTexture(textureSuv);
    spriteSuv.setPosition(420, 134);

    spriteVan.setTexture(textureVan);
    spriteVan.setPosition(300, 132);

    spriteTruck.setTexture(textureTruck);
    spriteTruck.setPosition(538, 134);

    //rent scene hover photos
    Texture textureBudget, textureMidrange, textureExpensive, textureLoop, textureRentButton;
    textureBudget.loadFromFile("./assets/credentials/hoverRentScene/Budget.png");
    textureMidrange.loadFromFile("./assets/credentials/hoverRentScene/MidRange.png");
    textureExpensive.loadFromFile("./assets/credentials/hoverRentScene/Expensive.png");
    textureLoop.loadFromFile("./assets/credentials/hoverRentScene/Searchbar.png");
    textureRentButton.loadFromFile("./assets/credentials/hoverRentScene/Rent button.png");

    Sprite spriteBudget, spriteMidrange, spriteExpensive, spriteLoop, spriteRentButton;
    spriteBudget.setTexture(textureBudget);
    spriteBudget.setPosition(58, 188);

    spriteMidrange.setTexture(textureMidrange);
    spriteMidrange.setPosition(258, 198);

    spriteExpensive.setTexture(textureExpensive);
    spriteExpensive.setPosition(458, 189);

    spriteLoop.setTexture(textureLoop);
    spriteLoop.setPosition(655, 185);

    spriteRentButton.setTexture(textureRentButton);
    spriteRentButton.setPosition(-20000, 555);

    //receptionist panel hover menu
    Texture hoverReceptionTexture;
    hoverReceptionTexture.loadFromFile("./assets/credentials/receptionHover/hoverReceptionScene.png");

    Sprite hoverReceptionSprite;
    hoverReceptionSprite.setTexture(hoverReceptionTexture);
    hoverReceptionSprite.setPosition(-1000, 230);

    Texture mainTexture, addCarTexture, carListTexture, logsTexture, addCarMenuTexture;
    mainTexture.loadFromFile("./assets/credentials/receptionHover/main.png");
    addCarTexture.loadFromFile("./assets/credentials/receptionHover/addCar.png");
    carListTexture.loadFromFile("./assets/credentials/receptionHover/carList.png");
    logsTexture.loadFromFile("./assets/credentials/receptionHover/logs.png");
    addCarMenuTexture.loadFromFile("./assets/credentials/receptionHover/addCarMenu.png");

    Sprite mainSprite, addCarSprite, carListSprite, logsSprite, addCarMenuSprite;
    mainSprite.setTexture(mainTexture);
    mainSprite.setPosition(55, 240);

    addCarSprite.setTexture(addCarTexture);
    addCarSprite.setPosition(55, 290);

    carListSprite.setTexture(carListTexture);
    carListSprite.setPosition(55, 340);

    logsSprite.setTexture(logsTexture);
    logsSprite.setPosition(55, 390);

    addCarMenuSprite.setTexture(addCarMenuTexture);

    while (window.isOpen()) {

        float dt = clock.restart().asSeconds();

        sf::Event event;
        Vector2i mousePos = Mouse::getPosition(window);

        cout << mousePos.x << " " << mousePos.y << endl;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
            }

            else if (event.type == Event::MouseButtonPressed && !sc->haltInput()) {

                if (event.mouseButton.button == 0) {

                    vector<Vector2f>* button = &sceneManager.getScene()->loginRegButton;

                    bool clickedButton = false;

                    if (sceneManager.getScene()->type == "reg" || sceneManager.getScene()->type == "log" ||
                        sceneManager.getScene()->type == "rent" || (sceneManager.getScene()->type == "rPanel" && addCarDraw))
                    {
                        // check if mouse.x is within button.x
                        if ((mousePos.x >= button->at(0).x && mousePos.x <= button->at(0).x + button->at(1).x)
                            && (mousePos.y >= button->at(0).y && mousePos.y <= button->at(0).y + button->at(1).y)) {

                            sceneManager.getScene()->getInputs();
                            clickedButton = true;

                            if (sceneManager.getScene()->type == "reg") {
                                if (logReg.checkLoginRegister(
                                    sceneManager.getScene()->inputs.at(0)->getInput(),
                                    sceneManager.getScene()->inputs.at(1)->getInput(),
                                    sceneManager.getScene()->inputs.at(3)->getInput(),
                                    sceneManager.getScene()->inputs.at(2)->getInput(),
                                    "register"))
                                {

                                    logReg.postUser(sceneManager.getScene()->inputs.at(0)->getInput(), sceneManager.getScene()->inputs.at(1)->getInput(),
                                        sceneManager.getScene()->inputs.at(3)->getInput(),
                                        sceneManager.getScene()->inputs.at(2)->getInput(), selectRole);
                                    shared_ptr<Scene> loginScene = make_shared<Login>("log");
                                    sceneManager.switchToScene(loginScene);
                                }
                            }
                            else if (sceneManager.getScene()->type == "log") {
                                if (logReg.checkLoginRegister("", "",
                                    sceneManager.getScene()->inputs.at(1)->getInput(),
                                    sceneManager.getScene()->inputs.at(0)->getInput(),
                                    "login")) {

                                    if (selectRole == "CUSTOMER") {
                                        email = sceneManager.getScene()->inputs.at(1)->getInput();

                                        shared_ptr<Scene> mainMenuScene = make_shared<MainMenu>("MainMenu", email);
                                        sceneManager.switchToScene(mainMenuScene);
                                    }
                                    else {
                                        shared_ptr<Scene> recepcionistPanelScene = make_shared<recepcionistPanel>("rPanel");
                                        sceneManager.switchToScene(recepcionistPanelScene);
                                    }
                                }

                            }
                            else if (sceneManager.getScene()->type == "rPanel") {
                                if ((mousePos.x >= 1000 && mousePos.x <= 1150) &&
                                    (mousePos.y >= 570 && mousePos.y <= 610)) {
                                    if (isClicked(event)) {
                                        shared_ptr<Scene> congratsScene = make_shared<endScreen>("end");
                                        sceneManager.switchToScene(congratsScene);
                                    }
                                }
                            }

                        }

                        if (!clickedButton) {
                            for (const auto& field : sceneManager.getScene()->inputs) {
                                field->selectField(Vector2f(event.mouseButton.x, event.mouseButton.y));
                            }
                        }

                        if ((mousePos.x >= 35 && mousePos.x <= 70) &&
                            (mousePos.y >= 505 && mousePos.y <= 535)) {
                            counter++;
                        }

                        if ((mousePos.x >= 1090 && mousePos.x <= 1220) && (mousePos.y >= 50 && mousePos.y <= 150))
                        {
                            if (sceneManager.getScene()->type == "reg")
                                counterModeRegister++;
                            else if (sceneManager.getScene()->type == "log")
                                counterModeLogin++;
                        }

                    }
                }
            }

            else if (event.type == Event::TextEntered) {
                sceneManager.getScene()->textHandler(window, event);
            }
        }

        sceneManager.update(dt);

        window.clear();

        if (sceneManager.getScene()->type == "reg")
            sceneManager.draw(window, counterModeRegister);
        else if (sceneManager.getScene()->type == "log")
            sceneManager.draw(window, counterModeLogin);
        else
            sceneManager.draw(window);

        if (counter % 2 == 0 && sceneManager.getScene()->type == "reg") {
            window.draw(checkMark);
            selectRole = "RECEPTIONIST";
        }
        else {
            selectRole = "CUSTOMER";
        }

        if (sceneManager.getScene()->type == "rent") {
            window.draw(vehicleTypeText);
            window.draw(manufacturerText);
            window.draw(modelText);
            window.draw(nameText);

            if ((mousePos.x >= 45 && mousePos.x <= 215) &&
                (mousePos.y >= 605 && mousePos.y <= 640)) {
                if (isClicked(event)) {
                    shared_ptr<Scene> congratsScene = make_shared<endScreen>("end");
                    sceneManager.switchToScene(congratsScene);
                }
            }
        }

        if (sceneManager.getScene()->type == "end") {
            if ((mousePos.x >= 35 && mousePos.x <= 120) &&
                (mousePos.y >= 630 && mousePos.y <= 670)) {
                if (isClicked(event)) {
                    shared_ptr<Scene> registerScene = make_shared<Register>("reg");
                    sceneManager.switchToScene(registerScene);
                }
            }
        }

        if (sceneManager.getScene()->type == "MainMenu") {
            window.draw(rentOneText);
            window.draw(rentTwoText);
            window.draw(rentThreeText);

            sceneManager.getScene()->getInputs();

            for (const auto& field : sceneManager.getScene()->inputs) {
                field->selectField(Vector2f(event.mouseButton.x, event.mouseButton.y));
            }

            if (mousePos.y >= 180 && mousePos.y <= 215) {
                if (mousePos.x >= 45 && mousePos.x <= 195) {
                    if (isClicked(event)) {
                        budgetChoice = 1;
                    }

                    window.draw(spriteBudget);
                }
                else if (mousePos.x >= 245 && mousePos.x <= 395) {
                    if (isClicked(event)) {
                        budgetChoice = 2;
                    }

                    window.draw(spriteMidrange);
                }
                else if (mousePos.x >= 450 && mousePos.x <= 590) {
                    if (isClicked(event)) {
                        budgetChoice = 3;
                    }

                    window.draw(spriteExpensive);
                }
                else if (mousePos.x >= 645 && mousePos.x <= 1020) {

                    window.draw(spriteLoop);
                }
            }
            else if (mousePos.y >= 590 && mousePos.y <= 635) {
                window.draw(spriteRentButton);

                if (isClicked(event)) {
                    shared_ptr<Scene> rent = make_shared<rentScene>("rent", email);
                    sceneManager.switchToScene(rent);
                }

                if (mousePos.x >= 75 && mousePos.x <= 370) {
                    spriteRentButton.setPosition(75, 590);

                    vehicleTypeText.setString(dataV.vehicleTypes.at(vehicleIndexes.at(0)));
                    manufacturerText.setString(dataV.manufacturers.at(vehicleIndexes.at(0)));
                    modelText.setString(dataV.models.at(vehicleIndexes.at(0)));
                    nameText.setString(dataV.names.at(vehicleIndexes.at(0)));
                }
                else if (mousePos.x >= 500 && mousePos.x <= 790) {
                    spriteRentButton.setPosition(488, 590);

                    vehicleTypeText.setString(dataV.vehicleTypes.at(vehicleIndexes.at(1)));
                    manufacturerText.setString(dataV.manufacturers.at(vehicleIndexes.at(1)));
                    modelText.setString(dataV.models.at(vehicleIndexes.at(1)));
                    nameText.setString(dataV.names.at(vehicleIndexes.at(1)));
                }
                else if (mousePos.x >= 900 && mousePos.x <= 1200) {
                    spriteRentButton.setPosition(895, 590);

                    vehicleTypeText.setString(dataV.vehicleTypes.at(vehicleIndexes.at(2)));
                    manufacturerText.setString(dataV.manufacturers.at(vehicleIndexes.at(2)));
                    modelText.setString(dataV.models.at(vehicleIndexes.at(2)));
                    nameText.setString(dataV.names.at(vehicleIndexes.at(2)));
                }
            }
            else if (mousePos.y >= 125 && mousePos.y <= 150) {
                if (mousePos.x >= 45 && mousePos.x <= 145) {
                    if (isClicked(event)) {
                        vehicleType = "Car";
                    }

                    window.draw(spriteCar);
                }
                else if (mousePos.x >= 165 && mousePos.x <= 270) {
                    if (isClicked(event)) {
                        vehicleType = "Motorcycle";
                    }

                    window.draw(spriteMotorcycle);
                }
                else if (mousePos.x >= 285 && mousePos.x <= 390) {
                    if (isClicked(event)) {
                        vehicleType = "Van";
                    }

                    window.draw(spriteVan);
                }
                else if (mousePos.x >= 410 && mousePos.x <= 510) {
                    if (isClicked(event)) {
                        vehicleType = "SUV";
                    }

                    window.draw(spriteSuv);
                }
                else if (mousePos.x >= 525 && mousePos.x <= 635) {
                    if (isClicked(event)) {
                        vehicleType = "Truck";
                    }

                    window.draw(spriteTruck);
                }
                else {
                    if (isClicked(event)) {
                        vehicleType = "allTypes";
                    }
                }
            }

            vehicleIndexes = handler.getVehiclePricesIndexes(budgetChoice, vehicleType, dataV.prices, dataV.vehicleTypes);

            if (vehicleIndexes.size() > 20) {
                vehicleIndexes.erase(vehicleIndexes.begin() + 20, vehicleIndexes.end());
            }

            rentOneText.setString(dataV.names.at(vehicleIndexes.at(0)));
            rentTwoText.setString(dataV.names.at(vehicleIndexes.at(1)));
            rentThreeText.setString(dataV.names.at(vehicleIndexes.at(2)));
        }

        if (sceneManager.getScene()->type == "rPanel") {

            window.draw(hoverReceptionSprite);
            window.draw(mainSprite);
            window.draw(addCarSprite);
            window.draw(carListSprite);
            window.draw(logsSprite);

            if (mousePos.x >= 0 && mousePos.x <= 250) {
                if (mousePos.y >= 230 && mousePos.y <= 285) {
                    if (isClicked(event)) {
                    }
                    hoverReceptionSprite.setPosition(0, 230);
                }

                else if (mousePos.y >= 286 && mousePos.y <= 330) {
                    if (isClicked(event)) {
                        sceneManager.getScene()->updateBg();
                        addCarDraw = true;
                    }
                    hoverReceptionSprite.setPosition(0, 285);
                }

                else if (mousePos.y >= 331 && mousePos.y <= 375)
                    hoverReceptionSprite.setPosition(0, 330);
                else if (mousePos.y >= 376 && mousePos.y <= 430)
                    hoverReceptionSprite.setPosition(0, 375);
                else
                    hoverReceptionSprite.setPosition(0, 230);
            }

        }

        window.display();
    }
}