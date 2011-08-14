# $NetBSD: Makefile,v 1.72 2011/08/14 07:20:53 obache Exp $

DISTNAME=	Tk-804.029
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5tk
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/htdocs/Tk/Tk.html
COMMENT=	Perl5 interface to Tk

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=	no

BUILD_DEPENDS+=	p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Tk/.packlist

MAKE_PARAMS=	X11=${X11BASE}

REPLACE_PERL+=	TextList/reindex.pl
REPLACE_PERL+=	pTk/Tcl-pTk
REPLACE_PERL+=	pTk/mkVFunc
REPLACE_PERL+=	demos/widget

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	PNG/Makefile.PL
SUBST_SED.prefix=	-e 's,%%LOCALBASE%%,${LOCALBASE},g'

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

.include "../../lang/perl5/module.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
