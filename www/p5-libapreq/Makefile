# $NetBSD: Makefile,v 1.2 2001/07/02 14:45:50 nra Exp $

DISTNAME=	libapreq-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://trainedmonkey.com/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	ap-perl-1.*:../../www/ap-perl

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libapreq/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
