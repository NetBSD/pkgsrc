# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:52 veego Exp $
#

DISTNAME=	VRML-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5vrm
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc/VRML.pm.html
COMMENT=	Set of VRML classes for Perl

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/VRML/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
