# $NetBSD: Makefile,v 1.1.1.1 2001/11/12 09:17:08 jlam Exp $

DISTNAME=	CGI-FastTemplate-1.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cgf
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	jlam@netbsd.org
COMMENT=	perl5 extension for managing templates

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/CGI/FastTemplate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
