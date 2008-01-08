# $NetBSD: Makefile,v 1.14 2008/01/08 22:49:47 heinz Exp $

DISTNAME=	YAML-0.66
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML/
COMMENT=	YAML implementation for Perl

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/YAML/.packlist
MAKE_PARAMS+=		< /dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
