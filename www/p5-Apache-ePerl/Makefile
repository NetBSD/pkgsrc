# $NetBSD: Makefile,v 1.16 2005/07/13 18:01:46 jlam Exp $
#

DISTNAME=		eperl-2.2.14
PKGNAME=		p5-Apache-ePerl-2.2.14
SVR4_PKGNAME=		p5aep
PKGREVISION=		1
CATEGORIES=		perl5 textproc www
MASTER_SITES=		http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/eperl/
COMMENT=		Perl5/Apache module of an ePerl text parser

DEPENDS+=		eperl-2.2.14:../../textproc/eperl

WRKSRC=			${WRKDIR}/${DISTNAME}/mod/Apache
PERL5_PACKLIST=		auto/Apache/ePerl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
