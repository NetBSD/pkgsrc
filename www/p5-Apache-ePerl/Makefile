# $NetBSD: Makefile,v 1.8 2003/03/29 12:42:52 jmmv Exp $
#

DISTNAME=		eperl-2.2.14
PKGNAME=		p5-Apache-ePerl-2.2.14
SVR4_PKGNAME=		p5aep
WRKSRC=			${WRKDIR}/${DISTNAME}/mod/Apache
CATEGORIES=		perl5 textproc www
MASTER_SITES=		http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/eperl/
COMMENT=		perl5/Apache module of an ePerl text parser

DEPENDS+=		eperl-2.2.14:../../textproc/eperl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/ePerl/.packlist

.include "../../www/ap-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
