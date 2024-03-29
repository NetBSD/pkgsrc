# $NetBSD: Makefile,v 1.27 2024/01/14 22:10:09 rillig Exp $
#

DISTNAME=	fvwm-themes-${THEM_VER}
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fvwm-themes/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}	\
		fvwm-themes-extra-${THEM_VER}.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://fvwm-themes.sourceforge.net/
COMMENT=	Configuration framework for fvwm2 with samples
LICENSE=	gnu-gpl-v2

DEPENDS+=	fvwm>=2.5.8:../../wm/fvwm
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

THEM_VER=	0.7.0
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	aclocal automake autoconf autoreconf
USE_TOOLS+=	bsdtar bzip2 gzip lex perl:run yacc
GNU_CONFIGURE=	YES

CONFIGURE_ENV+=		PERL=${PERL5}
CONFIGURE_ARGS+=	--with-ft-datadir=${PREFIX}/share/fvwm2
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
GNU_CONFIGURE_STRICT=	no	# autoconf 2.57 is too old

REPLACE_PERL+=	themes/cde/modules/create-buttonbar-config
REPLACE_PERL+=	themes/redmondxp/modules/FvwmThemesPanelManager

#### 1 ####
SUBST_CLASSES+=			Makefile
SUBST_FILES.Makefile=		Makefile.am Makefile.in
SUBST_SED.Makefile=		-e 's|FT_DATADIR=@FT_DATADIR@|FT_DATADIR=${DESTDIR}@FT_DATADIR@|'
SUBST_STAGE.Makefile=		pre-configure
SUBST_MESSAGE.Makefile=		Modify shell script (Makefile)

#### 2 ####
SUBST_CLASSES+=			fvwm-config
SUBST_FILES.fvwm-config=	bin/fvwm-themes-config-destdir.in
# -my @searchPath = ($userDir, $ftDataDir);
# +my @searchPath = ($userDir, "${DESTDIR}".$ftDataDir);
SUBST_SED.fvwm-config=		-e 's|hD = ($$userDir, $$ftDataDir|hD = ($$userDir, \"${DESTDIR}\".$$ftDataDir|'
SUBST_STAGE.fvwm-config=	pre-configure
SUBST_MESSAGE.fvwm-config=	Modify perl script bin/fvwm-themes-config-destdir.in

#### 3 ####
SUBST_CLASSES+=			fvwm-menuapp
SUBST_FILES.fvwm-menuapp=	bin/fvwm-themes-menuapp-destdir.in
# -my $ftDir = "@FT_DATADIR@"
# +my $ftDir = "${DESTDIR}@FT_DATADIR@"
SUBST_SED.fvwm-menuapp=		-e 's|$$userDir, $$ftDataDir|$$userDir, \"${DESTDIR}\".$$ftDataDir|'
SUBST_SED.fvwm-menuapp+=	-e 's|my $$ftDir = "@FT_DATADIR@"|my $$ftDir = \"${DESTDIR}@FT_DATADIR@\"|'
SUBST_STAGE.fvwm-menuapp=	pre-configure
SUBST_MESSAGE.fvwm-menuapp=	Fixing FT_DATADIR (fvwm-themes-datadir)

#### 4 ####
SUBST_CLASSES+=			gnome_session
SUBST_FILES.gnome_session=	configure.in
SUBST_SED.gnome_session=	-e 's|GNOME_SESSION=/usr/bin/gnome-session|GNOME_SESSION=${PREFIX}/bin/gnome-session|'
SUBST_STAGE.gnome_session=	pre-configure
SUBST_MESSAGE.gnome_session=	gnome-session path fixed

#### 5 ####
SUBST_CLASSES+=			root_prefix
SUBST_FILES.root_prefix=	bin/fvwm-themes-config-destdir.in
SUBST_SED.root_prefix=		-e 's|\/^$$ROOT_PREFIX\/\/|\|\^${DESTDIR}\|\||'
SUBST_STAGE.root_prefix=	pre-configure
SUBST_MESSAGE.root_prefix=	root_prefix tweak implementing

SUBST_CLASSES+=			destdir
SUBST_STAGE.destdir=		post-install
SUBST_FILES.destdir=		${DESTDIR}${PREFIX}/share/fvwm2/themes/current/theme.cfg
SUBST_SED.destdir=		-e 's,${DESTDIR}${PREFIX},${PREFIX},'

# Copied from bin/ and add -destdir onto its name.
# See following two targets.
bin_SCRIPTS_DESTDIR=	fvwm-themes-config fvwm-themes-menuapp

# Fake by making two different version of script under bin/
pre-patch:
	for i in ${bin_SCRIPTS_DESTDIR} ; do \
	${CP}  ${WRKSRC}/bin/$$i.in ${WRKSRC}/bin/$$i-destdir.in ;\
	done

post-install:
	${DESTDIR}${PREFIX}/bin/fvwm-themes-config-destdir --site --install \
		${DISTDIR}/fvwm-themes-extra-${THEM_VER}.tar.bz2
# Remove Fake version of script created by above target
	for i in ${bin_SCRIPTS_DESTDIR} ; do \
	 ${RM}  ${DESTDIR}${PREFIX}/bin/$$i-destdir ;\
	done
# Disable warning as 'executable bit is set on non-executable file' etc
	${FIND} ${DESTDIR}${PREFIX}/share/fvwm2/themes -type f     -exec ${CHMOD} -x     '{}' \;
	${FIND} ${DESTDIR}${PREFIX}/share/fvwm2/images -name \*xpm -exec ${CHMOD} -x,g-w '{}' \;
	${FIND} ${DESTDIR}${PREFIX}/share/fvwm2/images -type d     -exec ${CHMOD}    g-w '{}' \;
	${FIND} ${DESTDIR}${PREFIX}/share/fvwm2/sounds -name \*au  -exec ${CHMOD} -x,g-w '{}' \;
	${FIND} ${DESTDIR}${PREFIX}/share/fvwm2/sounds -type d     -exec ${CHMOD}    g-w '{}' \;

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
