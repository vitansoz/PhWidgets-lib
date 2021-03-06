#ifndef PT_BASIC_H
#define PT_BASIC_H

#include <photon/PtBasic.h>

#include "./Widget.h"


namespace PhWidgets
{
		
	class Basic:
		public Widget
	{
	public:

		struct ThisArgs
		{
			struct ArgUnsignedShort
			{
				enum eArgUnsignedShort
				{
					margin_height = Pt_ARG_MARGIN_HEIGHT,
					margin_width = Pt_ARG_MARGIN_WIDTH
				};
			};
			
			struct ArgUnsignedLong
			{
				enum eArgUnsignedLong
				{
					bandwidth_threshold = Pt_ARG_BANDWIDTH_THRESHOLD,
					basic_flags = Pt_ARG_BASIC_FLAGS
				};
			};

			struct ArgColor
			{
				enum eArgColor
				{
					bevel_color = Pt_ARG_BEVEL_COLOR,
					color = Pt_ARG_COLOR,
					dark_bevel_color = Pt_ARG_DARK_BEVEL_COLOR,
					dark_fill_color = Pt_ARG_DARK_FILL_COLOR,
					fill_color = Pt_ARG_FILL_COLOR,
					inline_color = Pt_ARG_INLINE_COLOR,
					light_bevel_color = Pt_ARG_LIGHT_BEVEL_COLOR,
					light_fill_color = Pt_ARG_LIGHT_FILL_COLOR,
					outline_color = Pt_ARG_OUTLINE_COLOR
				};
			};

			struct ArgChar
			{		
				enum eArgChar
				{
					bevel_contrast = Pt_ARG_BEVEL_CONTRAST,
					contrast = Pt_ARG_CONTRAST
				};
			};
			
			struct ArgPattern
			{
				enum eArgPattern
				{
					fill_pattern = Pt_ARG_FILL_PATTERN,
					trans_pattern = Pt_ARG_TRANS_PATTERN
				};
			};
			
			struct ArgUnsignedChar
			{
				enum eArgUnsignedChar
				{
					highlihgt_roundness = Pt_ARG_HIGHLIGHT_ROUNDNESS
				};
			};
			
			struct ArgPChar
			{
				enum eArgPChar
				{
					style = Pt_ARG_STYLE
				};
			};	
		};

		struct ThisCallbacks
		{
			struct Callback
			{
				enum eCallback
				{
					activate = Pt_CB_ACTIVATE,
					arm = Pt_CB_ARM,
					disarm = Pt_CB_DISARM,
					got_focus = Pt_CB_GOT_FOCUS,
					lost_focus = Pt_CB_LOST_FOCUS,
					menu = Pt_CB_MENU,
					repeat = Pt_CB_REPEAT
				};
			};
		};

		struct ArgUnsignedShort:
			public ArgumentsEx<Widget::ArgUnsignedShort>,
			public ThisArgs::ArgUnsignedShort
		{
			typedef ThisArgs::ArgUnsignedShort::eArgUnsignedShort eArgUnsignedShort;
		};
			
		struct ArgUnsignedLong:
			public ArgumentsEx<Widget::ArgUnsignedLong>,
			public ThisArgs::ArgUnsignedLong
		{
			typedef ThisArgs::ArgUnsignedLong::eArgUnsignedLong eArgUnsignedLong;
		};

		struct ArgColor:
			public ArgumentsEx<Widget::ArgColor>,
			public ThisArgs::ArgColor
		{
			typedef ThisArgs::ArgColor::eArgColor eArgColor;
		};

		struct ArgChar:
			public ThisArgs::ArgChar
		{
		};
			
		struct ArgPattern:
			public ThisArgs::ArgPattern
		{
		};
			
		struct ArgUnsignedChar:
			public ThisArgs::ArgUnsignedChar
		{
		};

		struct ArgPChar:
			public ArgumentsEx<Widget::ArgPChar>,
			public ThisArgs::ArgPChar
		{
			typedef ThisArgs::ArgPChar::eArgPChar eArgPChar;
		};	

		struct Callback:
			public ArgumentsEx<ThisCallbacks::Callback>,
			public Widget::Callback
		{
			typedef ThisCallbacks::Callback::eCallback eCallback;
		};

		struct Arguments:
			public ArgUnsignedShort,
			public ArgUnsignedLong,
			public ArgColor,
			public ArgChar,
			public ArgPattern,
			public ArgUnsignedChar,
			public ArgPChar,
			public Widget::Arguments
		{
		};

		struct Callbacks :
			public Callback,
			public Widget::Callbacks
		{
		};

	protected:

		typedef ResourceFrom<Widget::WidgetResourcesSingleton>::
			Define::String<ThisArgs::ArgPChar::eArgPChar>::
			Define::Color<ThisArgs::ArgColor::eArgColor>::
			Define::Scalar<ThisArgs::ArgUnsignedShort::eArgUnsignedShort, unsigned short>::
			Define::Scalar<ThisArgs::ArgChar::eArgChar, char>::
			//Define::Flag<ThisArgs::ArgLong::eArgLong, long>::
			Define::Flag<ThisArgs::ArgUnsignedLong::eArgUnsignedLong, unsigned long>::
			//Define::Flag<ThisArgs::ArgUnsigned::eArgUnsigned, unsigned>::

			Define::Link<ThisCallbacks::Callback::eCallback, PtCallback_t*>::

		resource_type WidgetResourcesSingleton;

		virtual void check();
						
	public:
		Basic(int abn);
		Basic(PtWidget_t *wdg);
		
		Basic(const Basic &rhs);

		Basic &operator=(const Basic &rhs);

		WidgetResourcesSingleton resource;
		
		phproperty<PgColor_t>::bind<Basic, ArgColor::eArgColor, Arguments::color> Color;
		phproperty<PgColor_t>::bind<Basic, ArgColor::eArgColor, Arguments::fill_color> FillColor;

		phwidgets_event<Basic, Basic::Callbacks::activate>		Activate;
		phwidgets_event<Basic, Basic::Callbacks::arm>			Arm;
		phwidgets_event<Basic, Basic::Callbacks::disarm>		Disarm;
		phwidgets_event<Basic, Basic::Callbacks::got_focus>		GotFocus;
		phwidgets_event<Basic, Basic::Callbacks::lost_focus>	LostFocus;
		phwidgets_event<Basic, Basic::Callbacks::menu>			Menu;
		phwidgets_event<Basic, Basic::Callbacks::repeat>		Repeat;

		void OnActivated(PtCallbackInfo_t *info);
		void OnArmed(PtCallbackInfo_t *info);
		void OnDisarmed(PtCallbackInfo_t *info);
		void OnGotFocused(PtCallbackInfo_t *info);
		void OnLostFocus(PtCallbackInfo_t *info);
		void OnMenu(PtCallbackInfo_t *info);
		void OnRepeat(PtCallbackInfo_t *info);
	};		  


	
}


#endif
