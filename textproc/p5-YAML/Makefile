# $NetBSD: Makefile,v 1.12 2006/10/28 08:37:40 obache Exp $

DISTNAME=	YAML-0.62
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
