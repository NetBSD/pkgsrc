# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:48 jlam Exp $
#

DISTNAME=	VRML-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5vrm
PKGREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc/VRML.pm.html
COMMENT=	Set of VRML classes for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/VRML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
