# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:52 veego Exp $

DISTNAME=	libapreq-0.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lap
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
