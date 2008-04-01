# $NetBSD: Makefile,v 1.57 2008/04/01 15:51:25 tonnerre Exp $

DISTNAME=	Tk-804.027
PKGNAME=	p5-Tk-804.027
PKGREVISION=	7
SVR4_PKGNAME=	p5tk
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/htdocs/Tk/Tk.html
COMMENT=	Perl5 interface to Tk

MAKE_JOBS_SAFE=	no

BUILD_DEPENDS+=	p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Tk/.packlist

MAKE_PARAMS=	X11=${X11BASE}

REPLACE_PERL+=	TextList/reindex.pl
REPLACE_PERL+=	pTk/Tcl-pTk
REPLACE_PERL+=	pTk/mkVFunc

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	PNG/Makefile.PL
SUBST_SED.prefix=	-e 's,%%LOCALBASE%%,${LOCALBASE},g'

.include "../../lang/perl5/module.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
