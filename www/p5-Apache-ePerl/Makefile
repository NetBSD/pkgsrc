# $NetBSD: Makefile,v 1.12 2004/01/20 12:27:59 agc Exp $
#

DISTNAME=		eperl-2.2.14
PKGNAME=		p5-Apache-ePerl-2.2.14
SVR4_PKGNAME=		p5aep
CATEGORIES=		perl5 textproc www
MASTER_SITES=		http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/eperl/
COMMENT=		Perl5/Apache module of an ePerl text parser

DEPENDS+=		eperl-2.2.14:../../textproc/eperl

WRKSRC=			${WRKDIR}/${DISTNAME}/mod/Apache
USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/ePerl/.packlist

.include "../../www/ap-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
