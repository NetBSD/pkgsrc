# $NetBSD: Makefile,v 1.23 2012/10/28 06:30:54 asau Exp $
#

DISTNAME=	VRML-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5vrm
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc
COMMENT=	Set of VRML classes for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/VRML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
