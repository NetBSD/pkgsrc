# $NetBSD: Makefile,v 1.8 2003/06/02 01:16:01 jschauma Exp $
#

DISTNAME=	VRML-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5vrm
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc/VRML.pm.html
COMMENT=	Set of VRML classes for Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/VRML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
