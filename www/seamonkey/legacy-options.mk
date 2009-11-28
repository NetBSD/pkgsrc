# $NetBSD: legacy-options.mk,v 1.1 2009/11/28 22:01:23 tnn Exp $
# used by www/seamonkey/legacy-Makefile.common

PKG_OPTIONS_VAR=	PKG_OPTIONS.gecko
PKG_SUPPORTED_OPTIONS=	debug official-mozilla-branding

.if ( ${MOZILLA_BIN} == "firefox-bin" || ${MOZILLA_BIN} == "seamonkey-bin" || ${MOZILLA_BIN} == "thunderbird-bin" )
PKG_SUPPORTED_OPTIONS  += mozilla-single-profile
.endif

.if ( ${MOZILLA} == "firefox3" )
PKG_SUPPORTED_OPTIONS  += mozilla-jemalloc
. if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS  += mozilla-jemalloc
. endif
.endif

.include "../../mk/bsd.options.mk"

# including jemalloc can cause issues on some platforms (e.g. SunOS 5.11)
# so expose an option to allow users to build FF without it.
# NOTE: This currently has only been known to happen on SunOS 5.11 x86
#       as a full list of systems is unknown the default is to still use it
.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mmozilla-single-profile)
CONFIGURE_ARGS+=	--enable-single-profile
.endif

# Enable Official mozilla.org Branding for Firefox or Thunderbird.
# Note that you cannot distribute builds with Official Branding
# without permission of the Mozilla Foundation.
# See http://www.mozilla.org/foundation/trademarks/
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding) && ${MOZILLA_BIN} != "seamonkey-bin"
CONFIGURE_ARGS+=	--enable-official-branding
# Mozilla prohibits distribution of packages with their trademarks.
# It is an open question if this makes the package non-Free.  Mozilla
# claims not, but currently pkgsrc has a "open source implies no
# redistribution restrictions" notion.
LICENSE=		mozilla-trademark-license
RESTRICTED=		Trademark holder prohibits distribution of modified versions.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif
