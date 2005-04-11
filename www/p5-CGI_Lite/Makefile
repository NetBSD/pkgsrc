# $NetBSD: Makefile,v 1.16 2005/04/11 21:47:56 tv Exp $
#

NAME=			CGI-Lite-2.02
DISTNAME=       	${NAME}
PKGNAME=        	p5-${NAME}
SVR4_PKGNAME=		p5cgl
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		Simple perl5 module for writing forms-based CGI programs

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
