# $NetBSD: Makefile,v 1.49 2005/12/12 18:04:47 joerg Exp $

DISTNAME=	Tk-804.027
PKGNAME=	p5-Tk-804.027
SVR4_PKGNAME=	p5tk
PKGREVISION=	3
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/htdocs/Tk/Tk.html
COMMENT=	Perl5 interface to Tk

BUILD_DEPENDS+= 	p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Tk/.packlist

MAKE_PARAMS=	X11=${X11BASE}

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	PNG/Makefile.PL
SUBST_SED.prefix=	-e 's,%%LOCALBASE%%,${LOCALBASE},g'

.include "../../lang/perl5/module.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
