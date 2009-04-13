# $NetBSD: buildlink3.mk,v 1.16 2009/04/13 12:19:14 rh Exp $

BUILDLINK_TREE+=	gnustep-gui

.if !defined(GNUSTEP_GUI_BUILDLINK3_MK)
GNUSTEP_GUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.16.0
BUILDLINK_ABI_DEPENDS.gnustep-gui+=	gnustep-gui>=0.16.0
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui

PRINT_PLIST_AWK+=	/^@dirrm include\/AppKit$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/Cocoa$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/GNUstepGUI$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/gnustep\/gui$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Applications$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/GSPrinting$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/GSPrinting\/GSLPR.bundle$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/GSPrinting\/GSLPR.bundle\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/TextConverters$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/TextConverters\/RTFConverter.bundle$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/TextConverters\/RTFConverter.bundle\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/libgmodel.bundle$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/libgmodel.bundle\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/NamedPicker.bundle$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/NamedPicker.bundle\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/StandardPicker.bundle$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources\/French.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources\/Swedish.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/WheelPicker.bundle$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/ColorPickers\/WheelPicker.bundle\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Images$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/KeyBindings$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSDataLinkPanel.gorm$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSPageLayout.gorm$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSPrintPanel.gorm$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSSpellPanel.gorm$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/Esperanto.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/German.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/Italian.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/Lojban.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/PostScript$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/PostScript\/PPD$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/PostScript\/PPD\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Services$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Services\/GSspell.service$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Services\/GSspell.service\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/AppKit$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/Cocoa$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/GNUstepGUI$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/gnustep\/gui$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Applications$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/GSPrinting$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/GSPrinting\/GSLPR.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/GSPrinting\/GSLPR.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/TextConverters$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/TextConverters\/RTFConverter.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/TextConverters\/RTFConverter.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/libgmodel.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/libgmodel.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/NamedPicker.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/NamedPicker.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/StandardPicker.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources\/French.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/StandardPicker.bundle\/Resources\/Swedish.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/WheelPicker.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/ColorPickers\/WheelPicker.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Images$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/KeyBindings$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSDataLinkPanel.gorm$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSPageLayout.gorm$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSPrintPanel.gorm$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/English.lproj\/GSSpellPanel.gorm$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/Esperanto.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/German.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/Italian.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-gui\/Versions\/0.16\/Resources\/Lojban.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/PostScript$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/PostScript\/PPD$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/PostScript\/PPD\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Services$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Services\/GSspell.service$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Services\/GSspell.service\/Resources$$/ { next; }

.include "../../devel/gnustep-base/buildlink3.mk"
.endif # GNUSTEP_GUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-gui
