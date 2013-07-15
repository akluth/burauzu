/**
 *   This file is part of Burauzu (ブラウズ).
 *
 *   Burauzu is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Burauzu is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Burauzu.  If not, see <http://www.gnu.org/licenses/>.
**/
#include "burauzu.h"
#include "ui_burauzu.h"

Burauzu::Burauzu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Burauzu)
{
    ui->setupUi(this);
}

Burauzu::~Burauzu()
{
    delete ui;
}

void Burauzu::on_actionQuit_triggered()
{
    qApp->quit();
}