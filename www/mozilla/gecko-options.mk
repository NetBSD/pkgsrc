# $NetBSD: gecko-options.mk,v 1.2 2005/09/28 12:04:29 rillig Exp $

PKG_OPTIONS_REQUIRED_GROUPS+=	gecko
PKG_OPTIONS_GROUP.gecko=	firefox mozilla
PKG_SUGGESTED_OPTIONS+=		firefox

.include "../../mk/bsd.prefs.mk"

# can be removed after 2005Q3
.if defined(GECKO_PROVIDER)
.  if ${GECKO_PROVIDER} == "firefox"
PKG_LEGACY_OPTIONS+=firefox
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable GECKO_PROVIDER used, use PKG_DEFAULT_OPTIONS+=firefox instead."
.  else
PKG_LEGACY_OPTIONS+=mozilla
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable GECKO_PROVIDER used, use PKG_DEFAULT_OPTIONS+=mozilla instead."
.  endif
.endif
