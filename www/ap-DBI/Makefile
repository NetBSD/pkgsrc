# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:49 jlam Exp $
#

DISTNAME=       ApacheDBI-0.87
PKGNAME=        ap-DBI-0.87
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/MERGL/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 Apache modules for DBI connections

DEPENDS+=	ap-perl-[0-9]*:../../www/ap-perl
DEPENDS+=	apache{,6}-1.3.*:../../www/apache

USE_PERL5=	# defined
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Apache/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
