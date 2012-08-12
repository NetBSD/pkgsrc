# $NetBSD: options.translations.mk,v 1.3 2012/08/12 08:55:54 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.contao${CT_VERS}-translations

.for l in ${CT_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=	lang-${l}
PKG_SUGGESTED_OPTIONS+=	lang-${l}
.endfor

.include "../../mk/bsd.options.mk"

.for l in ${PKG_OPTIONS:Mlang-*}
CT_LANGUAGES+=	${l:S/^lang-//1}
.endfor

.for l in ${CT_LANGUAGES}
CT_DISTFILES+=	${CT_TRANSLATIONS.${l}}
SITES.${CT_TRANSLATIONS.${l}}= \
	http://www.contao.org/en/download.html?iso=${l}&file=files/languages/${l}/
PLIST_SRC+=	PLIST.${l}
.endfor
