# $NetBSD: Makefile,v 1.7 2002/08/25 21:51:44 jlam Exp $
#

DISTNAME=       ApacheDBI-0.87
PKGNAME=        ap-DBI-0.87
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/MERGL/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 Apache modules for DBI connections

DEPENDS+=	ap-perl-[0-9]*:../../www/ap-perl
DEPENDS+=	apache{,6}-1.3.*:../../www/apache

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Apache/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
