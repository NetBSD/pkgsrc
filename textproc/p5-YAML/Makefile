# $NetBSD: Makefile,v 1.13 2007/11/29 14:19:49 wiz Exp $

DISTNAME=	YAML-0.66
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML/
COMMENT=	YAML implementation for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/YAML/.packlist
MAKE_PARAMS+=		< /dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
