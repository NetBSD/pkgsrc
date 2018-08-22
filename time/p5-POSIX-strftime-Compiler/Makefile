# $NetBSD: Makefile,v 1.5 2018/08/22 09:47:18 wiz Exp $

DISTNAME=	POSIX-strftime-Compiler-0.42
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POSIX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POSIX-strftime-Compiler/
COMMENT=	Perl extension for glibc compatible strftime for loggers/servers
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/POSIX/strftime/Compiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
