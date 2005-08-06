# $NetBSD: Makefile,v 1.18 2005/08/06 06:19:36 jlam Exp $
#

DISTNAME=		eperl-2.2.14
PKGNAME=		p5-Apache-ePerl-2.2.14
SVR4_PKGNAME=		p5aep
PKGREVISION=		2
CATEGORIES=		perl5 textproc www
MASTER_SITES=		http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/eperl/
COMMENT=		Perl5/Apache module of an ePerl text parser

DEPENDS+=		eperl>=2.2.14:../../textproc/eperl

WRKSRC=			${WRKDIR}/${DISTNAME}/mod/Apache
PERL5_PACKLIST=		auto/Apache/ePerl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
