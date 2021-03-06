/* ====================================================================== *
 * Copyright (c) 2010-2018 ZFFramework
 * Github repo: https://github.com/ZFFramework/ZFFramework
 * Home page: http://ZFFramework.com
 * Blog: http://zsaber.com
 * Contact: master@zsaber.com (Chinese and English only)
 * Distributed under MIT license:
 *   https://github.com/ZFFramework/ZFFramework/blob/master/LICENSE
 * ====================================================================== */
#include "ZFUIKit_test.h"

ZF_NAMESPACE_GLOBAL_BEGIN

zfclass ZFUIKit_ZFUIViewPositionOnScreen_test : zfextends ZFFramework_test_TestCase
{
    ZFOBJECT_DECLARE(ZFUIKit_ZFUIViewPositionOnScreen_test, ZFFramework_test_TestCase)

protected:
    zfoverride
    virtual void testCaseOnStart(void)
    {
        zfsuper::testCaseOnStart();
        ZFFramework_test_protocolCheck(ZFUIView);
        ZFFramework_test_protocolCheck(ZFUIViewPositionOnScreen);
        ZFUIWindow *window = zfnull;
        ZFUIView *container = zfnull;
        ZFUIKit_test_prepareTestWindow(window, container, this);

        zfblockedAlloc(ZFUIKit_test_Button, button);
        container->childAdd(button);
        button->layoutParam()->layoutAlignSet(ZFUIAlign::e_Center);
        button->buttonLabelTextSet("click me");

        ZFLISTENER_LOCAL(buttonOnClick, {
            zfLogTrimT() << "window size:" << ZFUIViewUtil::viewRoot(listenerData.sender->to<ZFUIView *>())->layoutedFrame().size;
            zfLogTrimT() << "clicked view's position:" << ZFUIViewPositionOnScreen(listenerData.sender->toAny());
        })
        button->observerAdd(ZFUIButton::EventButtonOnClick(), buttonOnClick);
    }
};
ZFOBJECT_REGISTER(ZFUIKit_ZFUIViewPositionOnScreen_test)

ZF_NAMESPACE_GLOBAL_END

