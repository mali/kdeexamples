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

#ifndef PLASMA_ANIMATION_EXAMPLE_H
#define PLASMA_ANIMATION_EXAMPLE_H

#include <KIcon>

#include <Plasma/Applet>
#include <Plasma/Svg>

class PlasmaAnimationExample : public Plasma::Applet
{
    Q_OBJECT

public:
    PlasmaAnimationExample(QObject *parent, const QVariantList &args);

    void init();

private Q_SLOTS:

    void startAll();
    void revertDirection();

private:
    QSequentialAnimationGroup *m_seqGroup;
};

#endif
