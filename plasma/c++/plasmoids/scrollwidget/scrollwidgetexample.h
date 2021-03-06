/**
 * Copyright 2010 Ryan Rix <ry@n.rix.si>
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
 **/

#ifndef SCROLLWIDGETEXAMPLE_H
#define SCROLLWIDGETEXAMPLE_H

#include <Plasma/Applet>

namespace Plasma
{
    class ScrollWidget;
    class Frame;
} // namespace Plasma

class QGraphicsLinearLayout;
class QGraphicsWidget;

class ScrollWidgetExample : public Plasma::Applet
{
Q_OBJECT
public:
    ScrollWidgetExample(QObject *parent, const QVariantList &args);

    void init();
    void addScrollerItem(const QString &text);

private:
    Plasma::ScrollWidget* m_scrollWidget;
    QGraphicsWidget* m_scroller;
    QGraphicsLinearLayout* m_scrollerLayout;
};

#endif
