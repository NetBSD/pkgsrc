# $NetBSD: options.mk,v 1.6 2009/03/15 19:15:45 jmcneill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.epiphany
PKG_SUPPORTED_OPTIONS=		avahi
# browser crashes with enchant
PKG_OPTIONS_OPTIONAL_GROUPS=	engine
PKG_OPTIONS_GROUP.engine=	firefox
PKG_SUGGESTED_OPTIONS=		avahi firefox
PLIST_VARS=			gecko

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-zeroconf
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spell-checker
.include "../../textproc/enchant/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfirefox)
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/find
CFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/find
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/necko
CFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/necko
CPPFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
CFLAGS+=	-I${BUILDLINK_PREFIX.firefox}/include/firefox/pref
# XXX the configure check doesn't work
CONFIGURE_ENV+=	ac_cv_header_nsIBadCertListener_h=yes
CONFIGURE_ARGS+=	--with-engine=mozilla
CONFIGURE_ARGS+=	--with-gecko=firefox
PLIST.gecko=	yes
.include "../../www/firefox/buildlink3.mk"
.endif
