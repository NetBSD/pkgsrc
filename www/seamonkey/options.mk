# $NetBSD: options.mk,v 1.4 2006/11/15 15:28:21 martin Exp $

PKG_OPTIONS_VAR		= PKG_OPTIONS.gecko
PKG_SUPPORTED_OPTIONS	= debug

.if ( ${MOZILLA_BIN} == "firefox-bin" || ${MOZILLA_BIN} == "thunderbird-bin" )
PKG_SUPPORTED_OPTIONS  += official-mozilla-branding
.endif

.include "../../mk/bsd.options.mk"

# this .if test looks backward, but the missing options disables debug,
# so it is correct
.if empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--disable-debug
.else
CONFIGURE_ARGS+=	--enable-debug
.endif

# Enable Official mozilla.org Branding for Firefox or Thunderbird.
# Note that you cannot distribute builds with Official Branding
# without permission of the Mozilla Foundation.
# See http://www.mozilla.org/foundation/trademarks/
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=	--enable-official-branding
RESTRICTED=		Cannot redistribute builds with Official Branding at this moment, we need permission of The Mozilla Foundation for this.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif
