# $NetBSD: Makefile,v 1.1.1.1 2001/07/06 14:37:13 abs Exp $

DISTNAME=		CGI-Minimal-1.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		perl5 module for simple CGI scripts

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Minimal/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
