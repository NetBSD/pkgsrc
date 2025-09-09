# $NetBSD: hacks.mk,v 1.2 2025/09/09 22:05:30 gutteridge Exp $

.if !defined(FVWM3_HACKS_MK)
FVWM3_HACKS_MK=	defined

### [Mon Sept 8 06:52:31 UTC 2025 : vins]
### The second argument of iconv() is of type `char **' in some
### implementations (including GNU libiconv), while it expects a `const char **'
### type in some others (at the very least on SunOS and NetBSD up to 9.*).
### This is a known issue. See https://gnats.netbsd.org/57672.
### Use the SUBST framework to fix the iconv prototype mismatch when needed.

.if (${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000) || ${OPSYS} == "SunOS"

CHECK_BUILTIN.iconv:=   yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=   no

.  if ${USE_BUILTIN.iconv:tl} == yes

PKG_HACKS+=		iconv_const

SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Applying portability fixes for SunOS iconv.
SUBST_FILES.iconv=	meson.build
SUBST_SED.iconv=	-e "s:conf.set('ICONV_ARG_CONST', ''):conf.set('ICONV_ARG_CONST', 'const'):g"

.  endif
.endif

.endif  # FVWM3_HACKS_MK
