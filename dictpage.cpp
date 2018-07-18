/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dictpage.h"
#include <QVBoxLayout>
#include <QScrollArea>

DictPage::DictPage(QWidget *parent)
    : QWidget(parent),
      m_api(new YoudaoAPI),
      m_wordLabel(new QLabel),
      m_infoLabel(new QLabel)
{
    QScrollArea *contentFrame = new QScrollArea;
    contentFrame->setWidgetResizable(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(contentFrame);

    QWidget *contentWidget = new QWidget;
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    contentLayout->setContentsMargins(20, 5, 20, 10);
    contentLayout->addWidget(m_wordLabel);
    contentLayout->addWidget(m_infoLabel);
    contentLayout->addStretch();

    contentFrame->setWidget(contentWidget);

    m_wordLabel->setWordWrap(true);
    m_infoLabel->setWordWrap(true);
    m_wordLabel->setStyleSheet("QLabel { color: #2CA7F8; font-size: 25px; }");
    m_infoLabel->setStyleSheet("QLabel { font-size: 16px; } ");

    connect(m_api, &YoudaoAPI::finished, this, &DictPage::handleQueryFinished);
}

DictPage::~DictPage()
{
}

void DictPage::queryWord(const QString &text)
{
    m_api->queryWord(text);
}

void DictPage::handleQueryFinished(const QString &queryText, const QString &ukPhonetic,
                                   const QString &usPhonetic, const QString &translationText)
{
    if (ukPhonetic.isEmpty() && usPhonetic.isEmpty()) {
//         pronLabel1->setVisible(false);
//         pronLabel2->setVisible(false);
//         pronButton1->setVisible(false);
//         pronButton2->setVisible(false);
    } else {
//         pronLabel1->setVisible(true);
//         pronLabel2->setVisible(true);
//         pronButton1->setVisible(true);
//         pronButton2->setVisible(true);

//         pronLabel1->setText(QString("英[%1]").arg(uk_phonetic));
//         pronLabel2->setText(QString("美[%1]").arg(us_phonetic));
    }

    m_wordLabel->setText(queryText);
    m_infoLabel->setText(translationText);
}