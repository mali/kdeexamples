/*
 * Copyright 2009 Mehmet Akmanalp <makmanalp@wpi.edu>
 * Copyright 2009 Adenilson Cavalcanti <savagobr@yahoo.com>
 * Copyright 2009 Igor Trindade Oliveira <igor_trindade@yahoo.com.br>
 * Copyright 2009 Marco Martin <notmart@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "PlasmaAnimationExample.h"

#include <QPainter>
#include <QPushButton>
#include <QFontMetrics>
#include <QSizeF>

#include <plasma/svg.h>
#include <plasma/theme.h>
#include <plasma/widgets/pushbutton.h>

#include <plasma/animations/animation.h>

#include <QGraphicsLinearLayout>
#include <QGraphicsLayoutItem>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

using namespace Plasma;

Q_DECLARE_METATYPE(QGraphicsWidget*)
Q_DECLARE_METATYPE(QGraphicsLayoutItem*)
Q_DECLARE_METATYPE(QEasingCurve)

K_EXPORT_PLASMA_APPLET(plasma-applet-pltest, PlasmaAnimationExample)

PlasmaAnimationExample::PlasmaAnimationExample(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args)
{
    // set a default size
    resize(300, 500);
}

void PlasmaAnimationExample::init()
{
    QGraphicsLinearLayout *mLayout = new QGraphicsLinearLayout(this);
    QGraphicsWidget *frontWidget = new QGraphicsWidget(this);
    QGraphicsLinearLayout *frontLayout = new QGraphicsLinearLayout(Qt::Vertical, frontWidget);

    PushButton* button1 = new PushButton(frontWidget);
    button1->setText("Press me!");

    PushButton *button2 = new PushButton(frontWidget);
    button2->setText("Pulse Animation!");

    PushButton* button3 = new PushButton(frontWidget);
    button3->setText("Grow Animation!");

    PushButton *button4 = new PushButton(frontWidget);
    button4->setText("Fade Animation!");

    PushButton *button5 = new PushButton(frontWidget);
    button5->setText("Slide Animation!");

    PushButton *button6 = new PushButton(frontWidget);
    button6->setText("Rotation stacked!");

    PushButton *button7 = new PushButton(frontWidget);
    button7->setText("Rotation!");

    PushButton *button8 = new PushButton(frontWidget);
    button8->setText("Zoom");

    PushButton *button9 = new PushButton(frontWidget);
    button9->setText("Water\neffect");

    PushButton *button10 = new PushButton(frontWidget);
    button10->setText("Shake!");

    PushButton *button11 = new PushButton(frontWidget);
    button11->setText("jsanim!");

    frontLayout->addItem(button1);
    frontLayout->addItem(button2);
    frontLayout->addItem(button3);
    frontLayout->addItem(button4);
    frontLayout->addItem(button8);
    frontLayout->addItem(button5);
    frontLayout->addItem(button6);
    frontLayout->addItem(button7);
    frontLayout->addItem(button9);
    frontLayout->addItem(button10);
    frontLayout->addItem(button11);

    qRegisterMetaType<QGraphicsLayoutItem *>("QGraphicsLayoutItem *");

    Animation* rotStackedAnim =
        Plasma::Animator::create(Plasma::Animator::RotationStackedAnimation);
    rotStackedAnim->setTargetWidget(frontWidget);
    QVariant var;
    var.setValue(static_cast<QGraphicsWidget*>(button6));
    rotStackedAnim->setProperty("backWidget", var);
    rotStackedAnim->setProperty("reference", Animation::Center);
    rotStackedAnim->setProperty("movementDirection", Animation::MoveRight);
    //rotStackedAnim->setProperty("duration", 1000);
    QVariant varLayout = rotStackedAnim->property("layout");
    mLayout->addItem(varLayout.value<QGraphicsLayoutItem*>());

    //animation
    Animation *rotAnim =
      Plasma::Animator::create(Plasma::Animator::RotationAnimation);
    rotAnim->setProperty("axis", Qt::ZAxis);
    rotAnim->setProperty("reference", Animation::Center);
    rotAnim->setProperty("angle", 180);
    rotAnim->setTargetWidget(button7);
    connect(button7, SIGNAL(clicked()), rotAnim, SLOT(start()));

    Animation *fadeAnim =
      Plasma::Animator::create(Plasma::Animator::FadeAnimation);
    fadeAnim->setProperty("startOpacity", 0.8);
    fadeAnim->setProperty("targetOpacity", 0.2);
    fadeAnim->setTargetWidget(button4);
    connect(button4, SIGNAL(clicked()), fadeAnim, SLOT(start()));

    Animation *pulseAnim =
      Plasma::Animator::create(Plasma::Animator::PulseAnimation);
    pulseAnim->setTargetWidget(button2);
    connect(button2, SIGNAL(clicked()), pulseAnim, SLOT(start()));

    Animation *growAnim =
      Plasma::Animator::create(Plasma::Animator::GrowAnimation);
    growAnim->setProperty("factor", 2.0);
    growAnim->setTargetWidget(button3);
    connect(button3, SIGNAL(clicked()), growAnim, SLOT(start()));

    Animation *slideAnim =
      Plasma::Animator::create(Plasma::Animator::SlideAnimation);
    slideAnim->setProperty("movementDirection", Animation::MoveDown);
    slideAnim->setProperty("distance", 30);
    slideAnim->setTargetWidget(button5);
    connect(button5, SIGNAL(clicked()), slideAnim, SLOT(start()));

    Animation *zoomAnim =
      Plasma::Animator::create(Plasma::Animator::ZoomAnimation);
    zoomAnim->setProperty("zoom", 2.0);
    zoomAnim->setTargetWidget(button8);
    connect(button8, SIGNAL(clicked()), zoomAnim, SLOT(start()));

    Animation *waterAnim =
      Plasma::Animator::create(Plasma::Animator::WaterAnimation);
    waterAnim->setTargetWidget(button9);
    waterAnim->setProperty("duration", 3000);
    waterAnim->setProperty("easingCurve", QVariant::fromValue(QEasingCurve(QEasingCurve::InOutSine)));
    connect(button9, SIGNAL(clicked()), waterAnim, SLOT(start()));

    Animation *shakeAnim =
        Plasma::Animator::create(Plasma::Animator::RotationAnimation);
    shakeAnim->setTargetWidget(button10);
    shakeAnim->setProperty("easingCurve",
        QVariant::fromValue(Plasma::Animator::create(Plasma::Animator::PendularCurve)));
    shakeAnim->setProperty("angle", 5);
    shakeAnim->setProperty("duration", 250);
    shakeAnim->setProperty("loopCount", 2);
    connect(button10, SIGNAL(clicked()), shakeAnim, SLOT(start()));

    QParallelAnimationGroup *parallel = new QParallelAnimationGroup(button11);
    Animation *jsAnim =
        Plasma::Animator::create(QString("ZoomAnimation"));
    if (!jsAnim) {
        qDebug() << "***********\n\nFailed loading javascript: ZoomAnimation!";

    } else {
        qDebug() << "***********\n\nSuccess creating javascript based animation";
        jsAnim->setTargetWidget(button11);
        parallel->addAnimation(jsAnim);

        jsAnim = Plasma::Animator::create(QString("FadeAnimation"));
        if (jsAnim) {
            jsAnim->setProperty("duration", 600);

            jsAnim->setTargetWidget(button11);
            parallel->addAnimation(jsAnim);
        } else {
            qDebug() << "***********\n\nFailed loading javascript: FadeAnimation!";
        }
        connect(button11, SIGNAL(clicked()), parallel, SLOT(start()));
    }
    //group 'em up!
    m_seqGroup = new QSequentialAnimationGroup(this);
    m_seqGroup->addAnimation(rotAnim);
    m_seqGroup->addAnimation(zoomAnim);
    m_seqGroup->addAnimation(fadeAnim);
    m_seqGroup->addAnimation(pulseAnim);
    m_seqGroup->addAnimation(growAnim);
    m_seqGroup->addAnimation(slideAnim);
    m_seqGroup->addAnimation(waterAnim);
    m_seqGroup->addAnimation(shakeAnim);
    m_seqGroup->addAnimation(rotStackedAnim);
    if (jsAnim) {
        m_seqGroup->addAnimation(parallel);
    }


    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(startAll()));
    QObject::connect(button6, SIGNAL(clicked()), this, SLOT(revertDirection()));
}

void PlasmaAnimationExample::revertDirection()
{
    if (m_seqGroup->property("direction") == QAbstractAnimation::Forward) {
        m_seqGroup->setProperty("direction", QAbstractAnimation::Backward);
    }

    m_seqGroup->start();
}
void PlasmaAnimationExample::startAll()
{
    if (m_seqGroup->property("direction") == QAbstractAnimation::Backward) {
        m_seqGroup->setProperty("direction", QAbstractAnimation::Forward);
    }

    m_seqGroup->start();
}


#include "PlasmaAnimationExample.moc"
