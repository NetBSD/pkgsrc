# $NetBSD: Makefile,v 1.3 2000/08/27 10:37:05 jlam Exp $
#

DISTNAME=		eperl-2.2.14
PKGNAME=		p5-Apache-ePerl-2.2.14
CATEGORIES=		perl5 textproc www
MASTER_SITES=		http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/eperl/

DEPENDS+=		eperl-2.2.14:../../textproc/eperl
DEPENDS+=		ap-perl-1.19:../../www/ap-perl

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/ePerl/.packlist

WRKSRC=			${WRKDIR}/${DISTNAME}/mod/Apache

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
