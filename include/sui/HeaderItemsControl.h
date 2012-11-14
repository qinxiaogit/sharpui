// 华勤科技版权所有 2010-2011
// 
// 文件名：HeaderItemsControl.h
// 功  能：带有头和内容的控件
// 
// 作  者：汪荣
// 时  间：2011-12-25
// 
// ============================================================================

# ifndef _UIHEADERITEMSCONTROL_H_
# define _UIHEADERITEMSCONTROL_H_

#include <sui/sharpuiconfig.h>
#include <sui/itemscontrol.h>

namespace ui
{

/// <summary>
/// HeaderItemsControl所有选择项的基类。
/// </summary>
class SHARPUI_API HeaderedItemsControl : public ItemsControl
{
public:

    HeaderedItemsControl();
    virtual ~HeaderedItemsControl();

    void SetText(const suic::String & text);
    suic::String GetText();

// 属性访问定义
public:

    DEFINE_PROPERTY(suic::ElementPtr, Header, val);
    DEFINE_PROPERTY(int, Indent, val);

public:

    int AddChild(suic::ObjectPtr child);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

    void OnSetterChanged(suic::SetterChangedEventArg& e);
    void OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader);

    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);

protected:

    suic::ElementPtr _header;
    int _indent;
};

typedef suic::shared<HeaderedItemsControl> HeaderItemsControlPtr;

inline int HeaderedItemsControl::GetIndent() const
{
    return _indent;
}

inline void HeaderedItemsControl::SetIndent(int val)
{
    _indent = val;
}

}

# endif
