# $NetBSD: Makefile,v 1.2 2001/11/26 06:50:31 jlam Exp $

DISTNAME=	CGI-FastTemplate-1.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cgf
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	jlam@netbsd.org
COMMENT=	perl5 extension for managing templates

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/FastTemplate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
