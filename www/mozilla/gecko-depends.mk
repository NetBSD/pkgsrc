.if !empty(PKG_OPTIONS:Mfirefox)
# firefox didn't have a pkgconfig file before 1.0.4
BUILDLINK_DEPENDS.firefox+= firefox>=1.0.4
.include "../../www/firefox/buildlink3.mk"
.else
.include "../../www/mozilla-gtk2/buildlink3.mk"
.endif
