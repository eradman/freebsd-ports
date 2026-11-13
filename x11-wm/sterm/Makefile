PORTNAME=	sterm
DISTVERSION=	0.9.3
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/st/
DISTNAME=	st-${DISTVERSION}

MAINTAINER=	ericshane@eradman.com
COMMENT=	Simple X terminal
WWW=		https://st.suckless.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		pkgconfig xorg
USE_XORG=	x11 xext xft

MAKE_ARGS=	PREFIX="${PREFIX}" VERSION="${PORTVERSION}" \
		X11INC="${LOCALBASE}/include" X11LIB="${LOCALBASE}/lib"

# This way we avoid running tic on st.info which does not work as expected.
BINARY_ALIAS=	tic=true

PLIST_FILES=	bin/st share/man/man1/st.1.gz

PORTDATA=	config.def.h st.info

PATCH_SITES=	https://st.suckless.org/patches/scrollback/
PATCHFILES=	st-scrollback-0.9.2.diff:-p1 \
			st-scrollback-mouse-0.9.2.diff:-p1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/st
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
